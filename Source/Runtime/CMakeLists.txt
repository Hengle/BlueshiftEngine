cmake_minimum_required(VERSION 2.8.12)

project(BlueshiftRuntime)

configure_file(
    "${PROJECT_SOURCE_DIR}/Version.h.in"
    "${PROJECT_SOURCE_DIR}/Version.h")

set(COMMON_ENGINE_FILES
    Precompiled.h
    Precompiled.cpp

    Public/BlueshiftEngine.h

    Public/Core/Allocator.h
    Public/Core/BinSearch.h
    Public/Core/Checksum_CRC32.h
    Public/Core/Checksum_MD5.h
    Public/Core/Heap.h
    Public/Core/Range.h
    Public/Core/UTF.h
    Public/Core/Str.h
    Public/Core/Variant.h
    Public/Core/VariantArg.h
    Public/Core/Guid.h
    Public/Core/ByteOrder.h
    Public/Core/CmdArgs.h
    Public/Core/Cmds.h
    Public/Core/CVars.h
    Public/Core/Timespan.h
    Public/Core/DateTime.h
    Public/Core/MinMaxCurve.h
    Public/Core/Dict.h
    Public/Core/Expr.h
    Public/Core/Lexer.h
    Public/Core/Task.h
    Public/Core/Event.h
    Public/Core/Object.h
    Public/Core/Property.h
    Public/Core/ScopeLock.h
    Public/Core/Serializable.h
    Public/Core/Signal.h
    Public/Core/SignalObject.h
    Public/Core/DynamicAABBTree.h
    Public/Core/JointPose.h
    Public/Core/StrColor.h
    Public/Core/Vec4Color.h
    Public/Core/Vertex.h 

    Public/Containers/StaticArray.h
    Public/Containers/HashIndex.h
    Public/Containers/HashMap.h
    Public/Containers/HashTable.h
    Public/Containers/Hierarchy.h
    Public/Containers/LinkList.h
    Public/Containers/Array.h
    Public/Containers/Pair.h
    Public/Containers/Stack.h
    Public/Containers/Queue.h 
    Public/Containers/StrArray.h
    Public/Containers/StrPool.h
    Public/Containers/LinkedList.h

    Public/Image/Image.h 
    Public/Image/DxtCodec.h
    Public/Image/DxtDecoder.h
    Public/Image/DxtEncoder.h

    Public/Math/AABB.h
    Public/Math/Angles.h
    Public/Math/Complex.h
    Public/Math/Color.h
    Public/Math/Color3.h
    Public/Math/Color4.h
    Public/Math/CQuaternion.h
    Public/Math/Curve.h
    Public/Math/Hermite.h
    Public/Math/Cylinder.h
    Public/Math/FloatConverter.h
    Public/Math/Frustum.h
    Public/Math/Half.h
    Public/Math/Hammersley.h
    Public/Math/Math.h
    Public/Math/MathCommon.h
    Public/Math/Matrix.h
    Public/Math/Matrix2.h
    Public/Math/Matrix3.h
    Public/Math/Matrix3x4.h
    Public/Math/Matrix4.h
    Public/Math/OBB.h
    Public/Math/Plane.h
    Public/Math/Pluecker.h
    Public/Math/Point.h
    Public/Math/Quaternion.h
    Public/Math/Random.h
    Public/Math/Ray.h
    Public/Math/Rect.h
    Public/Math/RGBE9995.h
    Public/Math/Rotation.h
    Public/Math/Sphere.h
    Public/Math/SphericalHarmonics.h
    Public/Math/Vector.h
    Public/Math/Vector2.h
    Public/Math/Vector3.h
    Public/Math/Vector4.h

    Public/Simd/Simd.h
    Public/Simd/Simd_AVX.h
    Public/Simd/Simd_Generic.h
    Public/Simd/Simd_SSE4.h
    Public/Simd/smmintrin_emu.h
    Public/Simd/immintrin_emu.h
    Public/Simd/AVX/avx.h
    Public/Simd/AVX/avxb.h
    Public/Simd/AVX/avxf.h
    Public/Simd/AVX/avxi.h
    Public/Simd/SSE/sse.h
    Public/Simd/SSE/sseb.h
    Public/Simd/SSE/ssef.h
    Public/Simd/SSE/ssei.h

    Public/Platform/cpuid.h
    Public/Platform/Intrinsics.h
    Public/Platform/PlatformAtomic.h
    Public/Platform/PlatformProcess.h
    Public/Platform/PlatformFile.h
    Public/Platform/PlatformThread.h
    Public/Platform/PlatformTLS.h
    Public/Platform/PlatformTime.h
    Public/Platform/PlatformSystem.h

    Public/File/File.h
    Public/File/FileSystem.h
    Public/File/ZipArchiver.h
  
    Public/RHI/RHI.h
    Public/RHI/RHIOpenGL.h

    Public/Engine/Common.h
    Public/Engine/GameClient.h
    Public/Engine/Console.h
    Public/Engine/Engine.h

    Public/Asset/Asset.h
    Public/Asset/AssetImporter.h
    Public/Asset/GuidMapper.h

    Public/AnimController/AnimBlendTree.h
    Public/AnimController/AnimClip.h
    Public/AnimController/AnimLayer.h
    Public/AnimController/AnimState.h
    Public/AnimController/AnimController.h

    Public/Animator/Animator.h
    Public/Animator/AnimStateBlender.h

    Public/Components/ComAnimation.h
    Public/Components/ComAnimator.h
    Public/Components/ComAudioListener.h
    Public/Components/ComAudioSource.h
    Public/Components/ComBoxCollider.h
    Public/Components/ComCamera.h
    Public/Components/ComCapsuleCollider.h
    Public/Components/ComCharacterController.h
    Public/Components/ComCharacterJoint.h
    Public/Components/ComCollider.h
    Public/Components/ComConeCollider.h
    Public/Components/ComConstantForce.h
    Public/Components/ComCylinderCollider.h
    Public/Components/ComFixedJoint.h
    Public/Components/ComHingeJoint.h
    Public/Components/ComJoint.h
    Public/Components/ComLight.h
    Public/Components/ComEnvironmentProbe.h
    Public/Components/ComLogic.h
    Public/Components/ComScript.h
    Public/Components/ComMeshCollider.h
    Public/Components/ComMeshRenderer.h
    Public/Components/ComTextRenderer.h
    Public/Components/Component.h
    Public/Components/ComParticleSystem.h
    Public/Components/ComRenderable.h
    Public/Components/ComRigidBody.h
    Public/Components/ComSensor.h
    Public/Components/ComSkinnedMeshRenderer.h
    Public/Components/ComSliderJoint.h
    Public/Components/ComSocketJoint.h
    Public/Components/ComSphereCollider.h
    Public/Components/ComSpline.h
    Public/Components/ComSpringJoint.h
    Public/Components/ComStaticMeshRenderer.h
    Public/Components/ComTransform.h
    Public/Components/ComWheelJoint.h
    Public/Components/ComVehicleWheel.h

    Public/Game/Entity.h
    Public/Game/Prefab.h
    Public/Game/MapRenderSettings.h
    Public/Game/GameWorld.h
    Public/Game/CastResult.h
    Public/Game/GameSettings.h
    Public/Game/TagLayerSettings.h
    Public/Game/PhysicsSettings.h
    Public/Game/PlayerSettings.h

    Public/StaticBatching/StaticBatch.h
    
    Public/Physics/Collider.h
    Public/Physics/Physics.h
    Public/Physics/PhysicsCollidable.h
    Public/Physics/PhysicsCollisionListener.h
    Public/Physics/PhysicsConstraint.h
    Public/Physics/PhysicsGenericConstraint.h
    Public/Physics/PhysicsGenericSpringConstraint.h
    Public/Physics/PhysicsHingeConstraint.h
    Public/Physics/PhysicsP2PConstraint.h
    Public/Physics/PhysicsSliderConstraint.h
    Public/Physics/PhysicsRigidBody.h
    Public/Physics/PhysicsSensor.h
    Public/Physics/PhysicsSystem.h
    Public/Physics/PhysicsVehicle.h
    Public/Physics/PhysicsWorld.h

    Public/Sound/Pcm.h
    Public/Sound/SoundSystem.h

    Public/Render/Anim.h
    Public/Render/BufferCache.h
    Public/Render/SkinningJointCache.h
    Public/Render/Font.h
    Public/Render/ParticleMesh.h
    Public/Render/GuiMesh.h
    Public/Render/Material.h
    Public/Render/Mesh.h
    Public/Render/Render.h
    Public/Render/RenderSystem.h
    Public/Render/RenderContext.h  
    Public/Render/ParticleSystem.h
    Public/Render/EnvProbe.h
    Public/Render/RenderObject.h
    Public/Render/RenderLight.h
    Public/Render/RenderCamera.h
    Public/Render/RenderWorld.h
    Public/Render/Shader.h
    Public/Render/Skeleton.h
    Public/Render/Skin.h
    Public/Render/SubMesh.h
    Public/Render/Texture.h

    Public/Platform/Platform.h

    Public/Input/InputSystem.h
    Public/Input/KeyCmd.h
    Public/Input/KeyCodes.h

    Public/Scripting/LuaVM.h

    Public/Profiler/Profiler.h

    Private/Core/Checksum_CRC32.cpp
    Private/Core/Checksum_MD5.cpp
    Private/Core/Heap.cpp
    Private/Core/UTF8.cpp
    Private/Core/UTF16.cpp
    Private/Core/Str.cpp
    Private/Core/Guid.cpp
    Private/Core/ByteOrder.cpp
    Private/Core/CmdArgs.cpp
    Private/Core/Cmds.cpp
    Private/Core/CVars.cpp
    Private/Core/Timespan.cpp
    Private/Core/DateTime.cpp
    Private/Core/Dict.cpp
    Private/Core/Expr.cpp
    Private/Core/MinMaxCurve.cpp
    Private/Core/Lexer.cpp
    Private/Core/Task.cpp
    Private/Core/Variant.cpp
    Private/Core/DynamicAABBTree.cpp
    Private/Core/Vec4Color.cpp

    Private/Containers/HashIndex.cpp

    Private/Image/ImageInternal.h
    Private/Image/Image.cpp
    Private/Image/ImageColorSpace.cpp
    Private/Image/ImageConvert.cpp
    Private/Image/ImageCompressDXT.cpp
    Private/Image/ImageCompressETC.cpp
    Private/Image/ImageDecompressDXT.cpp
    Private/Image/ImageDecompressPVRTC.cpp
    Private/Image/ImageDecompressETC.cpp
    Private/Image/ImageFile.cpp
    Private/Image/ImageFileBMP.cpp
    Private/Image/ImageFileDDS.cpp
    Private/Image/ImageFilePVR.cpp
    Private/Image/ImageFileHDR.cpp
    Private/Image/ImageFileJPG.cpp
    Private/Image/ImageFilePCX.cpp
    Private/Image/ImageFilePNG.cpp
    Private/Image/ImageFileTGA.cpp
    Private/Image/ImageFormat.cpp
    Private/Image/ImageProcess.cpp
    Private/Image/ImageResize.cpp
    Private/Image/DXTDecoder.cpp
    Private/Image/DXTEncoder.cpp

    Private/Math/Vector3.cpp
    Private/Math/Vector4.cpp
    Private/Math/Color3.cpp
    Private/Math/Color4.cpp
    Private/Math/RGBE9995.cpp
    Private/Math/AABB.cpp
    Private/Math/Frustum.cpp
    Private/Math/Matrix4.cpp
    Private/Math/Quaternion.cpp
    Private/Math/Angles.cpp
    Private/Math/Half.cpp
    Private/Math/OBB.cpp
    Private/Math/Ray.cpp
    Private/Math/Rect.cpp
    Private/Math/CQuaternion.cpp
    Private/Math/SphericalHarmonics.cpp
    Private/Math/Math.cpp
    Private/Math/Plane.cpp
    Private/Math/Rotation.cpp
    Private/Math/Complex.cpp
    Private/Math/Matrix2.cpp
    Private/Math/Matrix3x4.cpp
    Private/Math/Pluecker.cpp
    Private/Math/Sphere.cpp
    Private/Math/Cylinder.cpp
    Private/Math/Matrix3.cpp
    Private/Math/Point.cpp
    Private/Math/Vector2.cpp

    Private/SIMD/Simd.cpp
    Private/SIMD/Simd_AVX.cpp
    Private/SIMD/Simd_Generic.cpp
    Private/SIMD/Simd_SSE4.cpp

    Private/Platform/cpuid.cpp
    Private/Platform/PlatformBaseProcess.cpp
    Private/Platform/PlatformBaseFile.cpp
    Private/Platform/PlatformBaseThread.cpp
    Private/Platform/PlatformBaseTLS.cpp
    Private/Platform/PlatformBaseTime.cpp
    Private/Platform/PlatformBaseSystem.cpp

    Private/File/File.cpp
    Private/File/FileSystem.cpp
    Private/File/ZipArchiver.cpp

    Private/RHIOpenGL/OpenGL/OpenGL.h
    Private/RHIOpenGL/OpenGL/OpenGL.cpp
    Private/RHIOpenGL/RGLInternal.h
    Private/RHIOpenGL/RGLBuffer.cpp
    Private/RHIOpenGL/RGLCommon.cpp
    Private/RHIOpenGL/RGLQuery.cpp
    Private/RHIOpenGL/RGLRenderTarget.cpp
    Private/RHIOpenGL/RGLShader.cpp
    Private/RHIOpenGL/RGLState.cpp
    Private/RHIOpenGL/RGLSync.cpp
    Private/RHIOpenGL/RGLTexture.cpp
    Private/RHIOpenGL/RGLVertexFormat.cpp

    Private/Engine/Common.cpp
    Private/Engine/GameClient.cpp
    Private/Engine/Console.cpp
    Private/Engine/Engine.cpp

    Private/Asset/Asset.cpp
    Private/Asset/FolderAsset.cpp
    Private/Asset/FbxAsset.cpp
    Private/Asset/TextureAsset.cpp
    Private/Asset/ShaderAsset.cpp
    Private/Asset/MaterialAsset.cpp
    Private/Asset/FontAsset.cpp
    Private/Asset/MeshAsset.cpp
    Private/Asset/ParticleSystemAsset.cpp
    Private/Asset/SkeletonAsset.cpp
    Private/Asset/AnimAsset.cpp
    Private/Asset/JointMaskAsset.cpp
    Private/Asset/AnimControllerAsset.cpp
    Private/Asset/ScriptAsset.cpp
    Private/Asset/PrefabAsset.cpp
    Private/Asset/SoundAsset.cpp
    Private/Asset/MapAsset.cpp
    Private/Asset/AssetImporter.cpp
    Private/Asset/GuidMapper.cpp
  
    Private/AnimController/AnimBlendTree.cpp
    Private/AnimController/AnimClip.cpp
    Private/AnimController/AnimLayer.cpp
    Private/AnimController/AnimState.cpp
    Private/AnimController/AnimController.cpp

    Private/Animator/Animator.cpp
    Private/Animator/AnimStateBlender.cpp
  
    Private/Components/ComAnimation.cpp
    Private/Components/ComAnimator.cpp
    Private/Components/ComAudioListener.cpp
    Private/Components/ComAudioSource.cpp
    Private/Components/ComBoxCollider.cpp  
    Private/Components/ComCamera.cpp
    Private/Components/ComCapsuleCollider.cpp
    Private/Components/ComCharacterController.cpp
    Private/Components/ComCharacterJoint.cpp
    Private/Components/ComCollider.cpp
    Private/Components/ComConeCollider.cpp
    Private/Components/ComConstantForce.cpp
    Private/Components/ComCylinderCollider.cpp
    Private/Components/ComFixedJoint.cpp
    Private/Components/ComHingeJoint.cpp
    Private/Components/ComJoint.cpp
    Private/Components/ComLight.cpp
    Private/Components/ComEnvironmentProbe.cpp
    Private/Components/ComLogic.cpp
    Private/Components/ComScript.cpp
    Private/Components/ComMeshCollider.cpp
    Private/Components/ComMeshRenderer.cpp
    Private/Components/ComTextRenderer.cpp
    Private/Components/Component.cpp
    Private/Components/ComParticleSystem.cpp
    Private/Components/ComRenderable.cpp
    Private/Components/ComRigidBody.cpp
    Private/Components/ComSensor.cpp
    Private/Components/ComSkinnedMeshRenderer.cpp
    Private/Components/ComSliderJoint.cpp
    Private/Components/ComSocketJoint.cpp
    Private/Components/ComSphereCollider.cpp
    Private/Components/ComSpline.cpp
    Private/Components/ComSpringJoint.cpp
    Private/Components/ComStaticMeshRenderer.cpp
    Private/Components/ComTransform.cpp
    Private/Components/ComWheelJoint.cpp
    Private/Components/ComVehicleWheel.cpp

    Private/Game/Entity.cpp
    Private/Game/Prefab.cpp
    Private/Game/PrefabManager.cpp
    Private/Game/MapRenderSettings.cpp
    Private/Game/GameWorld.cpp
    Private/Game/CastResult.cpp  
    Private/Game/GameSettings.cpp
    Private/Game/TagLayerSettings.cpp
    Private/Game/PhysicsSettings.cpp
    Private/Game/PlayerSettings.cpp

    Private/StaticBatching/MeshCombiner.h
    Private/StaticBatching/MeshCombiner.cpp
    Private/StaticBatching/StaticBatch.cpp

    Private/Core/Event.cpp
    Private/Core/Object.cpp
    Private/Core/Serializable.cpp
    Private/Core/Signal.cpp
    Private/Core/SignalObject.cpp

    Private/Physics/ColliderInternal.h
    Private/Physics/PhysicsCVars.h
    Private/Physics/PhysicsInternal.h
    Private/Physics/Collider.cpp
    Private/Physics/ColliderManager.cpp
    Private/Physics/PhysicsCollidable.cpp
    Private/Physics/PhysicsCollisionListener.cpp
    Private/Physics/PhysicsConstraint.cpp
    Private/Physics/PhysicsCVars.cpp
    Private/Physics/PhysicsDebugDraw.cpp
    Private/Physics/PhysicsGenericConstraint.cpp
    Private/Physics/PhysicsGenericSpringConstraint.cpp
    Private/Physics/PhysicsHingeConstraint.cpp
    Private/Physics/PhysicsP2PConstraint.cpp
    Private/Physics/PhysicsSliderConstraint.cpp
    Private/Physics/PhysicsRigidBody.cpp
    Private/Physics/PhysicsSensor.cpp
    Private/Physics/PhysicsSystem.cpp
    Private/Physics/PhysicsVehicle.cpp
    Private/Physics/PhysicsWorld.cpp

    Private/Sound/Pcm.cpp
    Private/Sound/Pcm_DecodeWav.cpp
    Private/Sound/Pcm_DecodeOgg.cpp
    Private/Sound/Sound.cpp
    Private/Sound/SoundSystem.cpp

    Private/Render/BModel.h
    Private/Render/Anim.cpp
    Private/Render/Anim_banim.cpp
    Private/Render/Anim_optimize.cpp
    Private/Render/AnimManager.cpp
    Private/Render/BufferCache.cpp
    Private/Render/SkinningJointCache.cpp
    Private/Render/ParticleMesh.cpp
    Private/Render/GuiMesh.cpp
    Private/Render/Material.cpp
    Private/Render/MaterialManager.cpp
    Private/Render/Mesh.cpp
    Private/Render/Mesh_bmesh.cpp
    Private/Render/Mesh_CreateMesh.cpp
    Private/Render/Mesh_SortAndMerge.cpp
    Private/Render/MeshManager.cpp
    Private/Render/RenderSystem.cpp
    Private/Render/RenderContext.cpp
    Private/Render/ParticleSystem.cpp
    Private/Render/ParticleSystemManager.cpp
    Private/Render/EnvProbe.cpp
    Private/Render/RenderObject.cpp
    Private/Render/RenderLight.cpp
    Private/Render/RenderCamera.cpp
    Private/Render/RenderWorld.cpp
    Private/Render/RenderWorldDrawCamera.cpp
    Private/Render/RenderWorldDebugTools.cpp
    Private/Render/Shader.cpp
    Private/Render/ShaderManager.cpp
    Private/Render/Skeleton.cpp
    Private/Render/SkeletonManager.cpp
    Private/Render/Skin.cpp
    Private/Render/SkinManager.cpp
    Private/Render/SubMesh.cpp
    Private/Render/Texture.cpp
    Private/Render/TextureManager.cpp
    Private/Render/FontFace.h
    Private/Render/Font.cpp
    Private/Render/FontManager.cpp
    Private/Render/FontFaceBitmap.cpp
    Private/Render/FontFaceFreeType.cpp
    Private/Render/DrawSurf.h
    Private/Render/FrameData.h
    Private/Render/RBackEnd.h
    Private/Render/RenderCmd.h
    Private/Render/RenderCVars.h
    Private/Render/RenderInternal.h
    Private/Render/RenderPostProcess.h
    Private/Render/RenderTarget.h
    Private/Render/RenderUtils.h
    Private/Render/Simplex.h
    Private/Render/VertexFormat.h
    Private/Render/FrameData.cpp
    Private/Render/RB_DebugTools.cpp
    Private/Render/RB_DrawSimple.cpp
    Private/Render/RB_Main.cpp
    Private/Render/RB_GenericPass.cpp
    Private/Render/RB_ShadowPass.cpp
    Private/Render/RB_ForwardBasePass.cpp
    Private/Render/RB_ForwardAdditivePass.cpp
    Private/Render/RB_PostProcess.cpp
    Private/Render/RB_Batch.cpp
    Private/Render/RB_BatchRender.cpp
    Private/Render/RenderCVars.cpp
    Private/Render/RenderPostProcess.cpp
    Private/Render/RenderTarget.cpp
    Private/Render/RenderUtils.cpp
    Private/Render/VertexFormat.cpp  

    Private/Platform/Platform.cpp
    Private/Platform/PlatformGeneric.h
    Private/Platform/PlatformGeneric.cpp

    Private/Input/InputSystem.cpp
    Private/Input/KeyCmd.cpp

    Private/Scripting/LuaVM.cpp
    Private/Scripting/Math/LuaModule_Math.cpp
    Private/Scripting/Math/LuaModule_Complex.cpp
    Private/Scripting/Math/LuaModule_Vec2.cpp
    Private/Scripting/Math/LuaModule_Vec3.cpp
    Private/Scripting/Math/LuaModule_Vec4.cpp
    Private/Scripting/Math/LuaModule_Color3.cpp
    Private/Scripting/Math/LuaModule_Color4.cpp
    Private/Scripting/Math/LuaModule_Mat2.cpp
    Private/Scripting/Math/LuaModule_Mat3.cpp
    Private/Scripting/Math/LuaModule_Mat3x4.cpp
    Private/Scripting/Math/LuaModule_Mat4.cpp
    Private/Scripting/Math/LuaModule_Quaternion.cpp
    Private/Scripting/Math/LuaModule_Angles.cpp
    Private/Scripting/Math/LuaModule_Rotation.cpp
    Private/Scripting/Math/LuaModule_Plane.cpp
    Private/Scripting/Math/LuaModule_Sphere.cpp
    Private/Scripting/Math/LuaModule_Cylinder.cpp
    Private/Scripting/Math/LuaModule_AABB.cpp
    Private/Scripting/Math/LuaModule_OBB.cpp
    Private/Scripting/Math/LuaModule_Frustum.cpp
    Private/Scripting/Math/LuaModule_Ray.cpp
    Private/Scripting/Math/LuaModule_Point.cpp
    Private/Scripting/Math/LuaModule_Rect.cpp
    Private/Scripting/Engine/LuaModule_Common.cpp
    Private/Scripting/Input/LuaModule_InputSystem.cpp
    Private/Scripting/Screen/LuaModule_Screen.cpp
    Private/Scripting/Physics/LuaModule_Physics.cpp
    Private/Scripting/Core/LuaModule_Str.cpp
    Private/Scripting/Core/LuaModule_Guid.cpp
    Private/Scripting/Core/LuaModule_Object.cpp
    Private/Scripting/File/LuaModule_FileSystem.cpp
    Private/Scripting/File/LuaModule_File.cpp
    Private/Scripting/Asset/LuaModule_Asset.cpp
    Private/Scripting/Asset/LuaModule_TextureAsset.cpp
    Private/Scripting/Asset/LuaModule_ShaderAsset.cpp
    Private/Scripting/Asset/LuaModule_MaterialAsset.cpp
    Private/Scripting/Asset/LuaModule_SkeletonAsset.cpp
    Private/Scripting/Asset/LuaModule_MeshAsset.cpp
    Private/Scripting/Asset/LuaModule_AnimAsset.cpp
    Private/Scripting/Asset/LuaModule_AnimControllerAsset.cpp
    Private/Scripting/Asset/LuaModule_SoundAsset.cpp
    Private/Scripting/Asset/LuaModule_MapAsset.cpp
    Private/Scripting/Asset/LuaModule_PrefabAsset.cpp
    Private/Scripting/Components/LuaModule_Component.cpp
    Private/Scripting/Components/LuaModule_ComTransform.cpp
    Private/Scripting/Components/LuaModule_ComCollider.cpp
    Private/Scripting/Components/LuaModule_ComBoxCollider.cpp
    Private/Scripting/Components/LuaModule_ComSphereCollider.cpp
    Private/Scripting/Components/LuaModule_ComCylinderCollider.cpp
    Private/Scripting/Components/LuaModule_ComCapsuleCollider.cpp
    Private/Scripting/Components/LuaModule_ComMeshCollider.cpp
    Private/Scripting/Components/LuaModule_ComRigidBody.cpp
    Private/Scripting/Components/LuaModule_ComSensor.cpp
    Private/Scripting/Components/LuaModule_ComJoint.cpp
    Private/Scripting/Components/LuaModule_ComFixedJoint.cpp
    Private/Scripting/Components/LuaModule_ComHingeJoint.cpp
    Private/Scripting/Components/LuaModule_ComSocketJoint.cpp
    Private/Scripting/Components/LuaModule_ComSliderJoint.cpp
    Private/Scripting/Components/LuaModule_ComSpringJoint.cpp
    Private/Scripting/Components/LuaModule_ComWheelJoint.cpp
    Private/Scripting/Components/LuaModule_ComCharacterJoint.cpp
    Private/Scripting/Components/LuaModule_ComConstantForce.cpp
    Private/Scripting/Components/LuaModule_ComCharacterController.cpp
    Private/Scripting/Components/LuaModule_ComRenderable.cpp
    Private/Scripting/Components/LuaModule_ComMeshRenderer.cpp
    Private/Scripting/Components/LuaModule_ComStaticMeshRenderer.cpp
    Private/Scripting/Components/LuaModule_ComSkinnedMeshRenderer.cpp
    Private/Scripting/Components/LuaModule_ComAnimation.cpp
    Private/Scripting/Components/LuaModule_ComAnimator.cpp
    Private/Scripting/Components/LuaModule_ComTextRenderer.cpp
    Private/Scripting/Components/LuaModule_ComParticleSystem.cpp
    Private/Scripting/Components/LuaModule_ComLight.cpp
    Private/Scripting/Components/LuaModule_ComCamera.cpp
    Private/Scripting/Components/LuaModule_ComAudioListener.cpp
    Private/Scripting/Components/LuaModule_ComAudioSource.cpp
    Private/Scripting/Components/LuaModule_ComSpline.cpp
    Private/Scripting/Components/LuaModule_ComScript.cpp
    Private/Scripting/Components/LuaModule_ComVehicleWheel.cpp
    Private/Scripting/Game/LuaModule_Entity.cpp
    Private/Scripting/Game/LuaModule_GameWorld.cpp

    Private/Profiler/Profiler.cpp)

set(WINDOWS_ENGINE_FILES
    Public/Platform/Windows/PlatformWinProcess.h
    Public/Platform/Windows/PlatformWinFile.h
    Public/Platform/Windows/PlatformWinThread.h
    Public/Platform/Windows/PlatformWinTLS.h
    Public/Platform/Windows/PlatformWinTime.h
    Public/Platform/Windows/PlatformWinSystem.h
    Public/Platform/Windows/PlatformWinUtils.h

    Private/Platform/Windows/PlatformWinProcess.cpp
    Private/Platform/Windows/PlatformWinFile.cpp
    Private/Platform/Windows/PlatformWinThread.cpp
    Private/Platform/Windows/PlatformWinTLS.cpp
    Private/Platform/Windows/PlatformWinTime.cpp
    Private/Platform/Windows/PlatformWinSystem.cpp
    Private/Platform/Windows/PlatformWinUtils.cpp

    Private/Platform/PlatformWin.h
    Private/Platform/PlatformWin.cpp

    Public/Network/Socket.h
    Public/Network/Packet.h
    Private/Network/Socket.cpp
    Private/Network/Packet.cpp

    Private/Sound/SoundSystemAL.cpp
    Private/Sound/SoundBufferAL.cpp
    Private/Sound/SoundSourceAL.cpp
    
    Private/Sound/SoundSystemDS.cpp
    Private/Sound/SoundBufferDS.cpp
    Private/Sound/SoundSourceDS.cpp)

set(ANDROID_ENGINE_FILES
    Public/Platform/Posix/PlatformPosixProcess.h
    Public/Platform/Posix/PlatformPosixTLS.h
    Public/Platform/Posix/PlatformPosixTime.h
    Public/Platform/Linux/PlatformLinuxProcess.h
    Public/Platform/Linux/PlatformLinuxTime.h
    Public/Platform/Android/PlatformAndroidProcess.h
    Public/Platform/Android/PlatformAndroidSystem.h
    Public/Platform/Android/PlatformAndroidThread.h
    Public/Platform/Android/PlatformAndroidFile.h

    Private/Platform/Posix/PlatformPosixProcess.cpp
    Private/Platform/Posix/PlatformPosixTLS.cpp
    Private/Platform/Posix/PlatformPosixTime.cpp
    Private/Platform/Linux/PlatformLinuxProcess.cpp
    Private/Platform/Linux/PlatformLinuxTime.cpp
    Private/Platform/Android/PlatformAndroidProcess.cpp 
    Private/Platform/Android/PlatformAndroidSystem.cpp 
    Private/Platform/Android/PlatformAndroidThread.cpp
    Private/Platform/Android/PlatformAndroidFile.cpp
    Private/Platform/PlatformAndroid.h
    Private/Platform/PlatformAndroid.cpp

    Public/PlatformUtils/Android/AndroidJNI.h
    Public/PlatformUtils/Android/AndroidGPUInfo.h

    Private/PlatformUtils/Android/AndroidJNI.cpp
    Private/PlatformUtils/Android/AndroidGPUInfo.cpp

    Private/Sound/SoundSystemSLES.cpp
    Private/Sound/SoundBufferSLES.cpp
    Private/Sound/SoundSourceSLES.cpp)

set(UNIX_ENGINE_FILES
    Public/Platform/Posix/PlatformPosixProcess.h
    Public/Platform/Posix/PlatformPosixFile.h
    Public/Platform/Posix/PlatformPosixThread.h
    Public/Platform/Posix/PlatformPosixTLS.h
    Public/Platform/Posix/PlatformPosixTime.h
    Public/Platform/Posix/PlatformPosixSystem.h

    Private/Platform/Posix/PlatformPosixProcess.cpp
    Private/Platform/Posix/PlatformPosixFile.cpp
    Private/Platform/Posix/PlatformPosixThread.cpp
    Private/Platform/Posix/PlatformPosixTLS.cpp
    Private/Platform/Posix/PlatformPosixTime.cpp
    Private/Platform/Posix/PlatformPosixSystem.cpp

    Private/Sound/SoundSystemAL.cpp
    Private/Sound/SoundBufferAL.cpp
    Private/Sound/SoundSourceAL.cpp)

set(LINUX_ENGINE_FILES
    ${UNIX_ENGINE_FILES}
    Public/Platform/Linux/PlatformLinuxProcess.h
    Public/Platform/Linux/PlatformLinuxThread.h
    Private/Platform/Linux/PlatformLinuxProcess.cpp
    Private/Platform/Linux/PlatformLinuxThread.cpp)

set(APPLE_ENGINE_FILES
    ${UNIX_ENGINE_FILES}
    Public/Platform/Apple/PlatformAppleTime.h
    Public/Platform/Apple/PlatformAppleProcess.h
    Public/Platform/Apple/PlatformAppleSystem.h
    Public/Platform/Apple/PlatformAppleThread.h

    Private/Platform/Apple/PlatformAppleTime.cpp
    Private/Platform/Apple/PlatformAppleProcess.mm
    Private/Platform/Apple/PlatformAppleSystem.mm
    Private/Platform/Apple/PlatformAppleThread.cpp)
    
set(IOS_ENGINE_FILES
    ${APPLE_ENGINE_FILES}
    Public/Platform/IOS/PlatformIOSFile.h
    Public/Platform/IOS/PlatformIOSProcess.h
    Public/Platform/IOS/PlatformIOSSystem.h

    Private/Platform/IOS/PlatformIOSFile.mm
    Private/Platform/IOS/PlatformIOSProcess.mm
    Private/Platform/IOS/PlatformIOSSystem.mm
    Private/Platform/PlatformIOS.h
    Private/Platform/PlatformIOS.mm

    Public/PlatformUtils/iOS/iOSDevice.h
    Private/PlatformUtils/iOS/iOSDevice.mm)

set(MACOS_ENGINE_FILES
    ${APPLE_ENGINE_FILES}
    Public/Platform/MacOS/PlatformMacOSProcess.h
    Public/Platform/MacOS/PlatformMacOSSystem.h

    Private/Platform/MacOS/PlatformMacOSProcess.mm
    Private/Platform/MacOS/PlatformMacOSSystem.mm
    Private/Platform/PlatformMacOS.h
    Private/Platform/PlatformMacOS.mm

    Public/Network/Socket.h
    Public/Network/Packet.h
    Private/Network/Socket.cpp
    Private/Network/Packet.cpp)

set(WINDOWS_RENDERER_FILES
    Private/RHIOpenGL/OpenGL/GGL/gglcore32.c
    Private/RHIOpenGL/OpenGL/GGL/gglcore32.h
    Private/RHIOpenGL/OpenGL/GGL/gwgl.c
    Private/RHIOpenGL/OpenGL/GGL/gwgl.h
    Private/RHIOpenGL/OpenGL/OpenGL3.h
    Private/RHIOpenGL/OpenGL/OpenGL3.cpp
    Private/RHIOpenGL/OpenGL/OpenGL4.h
    Private/RHIOpenGL/OpenGL/OpenGL4.cpp
    Private/RHIOpenGL/OpenGL/WinOpenGL.h
    Private/RHIOpenGL/RGLPlatformWin.cpp)

set(ANDROID_RENDERER_FILES
    Private/RHIOpenGL/OpenGL/GGL/ggles3.c
    Private/RHIOpenGL/OpenGL/GGL/ggles3.h
    Private/RHIOpenGL/OpenGL/GGL/gegl.c
    Private/RHIOpenGL/OpenGL/GGL/gegl.h
    Private/RHIOpenGL/OpenGL/OpenGLES3.h
    Private/RHIOpenGL/OpenGL/OpenGLES3.cpp
    Private/RHIOpenGL/OpenGL/AndroidOpenGL.h
    Private/RHIOpenGL/OpenGL/AndroidOpenGL.cpp
    Private/RHIOpenGL/RGLPlatformAndroid.cpp)

set(IOS_RENDERER_FILES
    Private/RHIOpenGL/OpenGL/GGL/ggles3.c
    Private/RHIOpenGL/OpenGL/GGL/ggles3.h
    Private/RHIOpenGL/OpenGL/OpenGLES3.h
    Private/RHIOpenGL/OpenGL/OpenGLES3.cpp
    Private/RHIOpenGL/OpenGL/IOSOpenGL.h
    Private/RHIOpenGL/OpenGL/IOSOpenGL.mm
    Private/RHIOpenGL/RGLPlatformIOS.mm)

set(MACOS_RENDERER_FILES
    Private/RHIOpenGL/OpenGL/GGL/gglcore32.c
    Private/RHIOpenGL/OpenGL/GGL/gglcore32.h
    Private/RHIOpenGL/OpenGL/OpenGL3.h
    Private/RHIOpenGL/OpenGL/OpenGL3.cpp
    Private/RHIOpenGL/OpenGL/MacOSOpenGL.h
    Private/RHIOpenGL/RGLPlatformMacOS.mm)

if (NOT PLATFORM_WINDOWS)
    list(APPEND COMPILING_DISABLED_SOURCES ${WINDOWS_ENGINE_FILES} ${WINDOWS_RENDERER_FILES})
endif ()

if (NOT PLATFORM_MACOS)
    list(APPEND COMPILING_DISABLED_SOURCES ${MACOS_ENGINE_FILES} ${MACOS_RENDERER_FILES})
endif ()

if (NOT PLATFORM_LINUX)
    list(APPEND COMPILING_DISABLED_SOURCES ${LINUX_ENGINE_FILES})
endif ()

if (NOT PLATFORM_ANDROID)
    list(APPEND COMPILING_DISABLED_SOURCES ${ANDROID_ENGINE_FILES} ${ANDROID_RENDERER_FILES})
endif ()

if (NOT PLATFORM_IOS)
    list(APPEND COMPILING_DISABLED_SOURCES ${IOS_ENGINE_FILES} ${IOS_RENDERER_FILES})
endif ()

set_source_files_properties(${COMPILING_DISABLED_SOURCES} PROPERTIES HEADER_FILE_ONLY TRUE)

if (PLATFORM_WINDOWS)
    set_source_files_properties(${WINDOWS_ENGINE_FILES} ${WINDOWS_RENDERER_FILES} PROPERTIES HEADER_FILE_ONLY FALSE)

    if (NOT USE_WINDOWS_OPENAL)
        set_source_files_properties(
            Private/Sound/SoundSystemAL.cpp 
            Private/Sound/SoundBufferAL.cpp
            Private/Sound/SoundSourceAL.cpp PROPERTIES HEADER_FILE_ONLY TRUE)
    else ()
        set_source_files_properties(
            Private/Sound/SoundSystemDS.cpp
            Private/Sound/SoundBufferDS.cpp
            Private/Sound/SoundSourceDS.cpp PROPERTIES HEADER_FILE_ONLY TRUE)
    endif ()
elseif (PLATFORM_MACOS)
    set_source_files_properties(${MACOS_ENGINE_FILES} ${MACOS_RENDERER_FILES} PROPERTIES HEADER_FILE_ONLY FALSE)
elseif (PLATFORM_LINUX)
    set_source_files_properties(${LINUX_ENGINE_FILES} PROPERTIES HEADER_FILE_ONLY FALSE)
elseif (PLATFORM_ANDROID)
    set_source_files_properties(${ANDROID_ENGINE_FILES} ${ANDROID_RENDERER_FILES} PROPERTIES HEADER_FILE_ONLY FALSE)
elseif (PLATFORM_IOS)
    set_source_files_properties(${IOS_ENGINE_FILES} ${IOS_RENDERER_FILES} PROPERTIES HEADER_FILE_ONLY FALSE)
endif ()

set(ENGINE_FILES
    ${COMMON_ENGINE_FILES}
    ${WINDOWS_ENGINE_FILES}
    ${ANDROID_ENGINE_FILES}
    ${LINUX_ENGINE_FILES}
    ${MACOS_ENGINE_FILES}
    ${IOS_ENGINE_FILES})

set(RENDERER_FILES
    ${WINDOWS_RENDERER_FILES}
    ${ANDROID_RENDERER_FILES}
    ${IOS_RENDERER_FILES}
    ${MACOS_RENDERER_FILES})

set(ALL_FILES
    ${ENGINE_FILES}
    ${RENDERER_FILES})

auto_source_group(${ALL_FILES})

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${ENGINE_INCLUDE_DIR}/Runtime/Public
    ${ENGINE_INCLUDE_DIR}/ThirdParty
    ${ENGINE_INCLUDE_DIR}/ThirdParty/asio/include)

enable_precompiled_header(Precompiled.h Precompiled.cpp ENGINE_FILES)

if (PLATFORM_ANDROID)
    include_directories(${ANDROID_NDK}/sources/android/cpufeatures)
    set(CPU_FEATURES_FILE ${ANDROID_NDK}/sources/android/cpufeatures/cpu-features.c)

    add_library(${PROJECT_NAME} STATIC ${ALL_FILES} ${CPU_FEATURES_FILE})

    target_link_libraries(${PROJECT_NAME}
        android
        atomic
        log
        EGL
        GLESv3
        OpenSLES)
else ()
    add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
endif ()

if (APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++0x"
        XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++"
        XCODE_ATTRIBUTE_CLANG_MODULES_AUTOLINK "NO"
        XCODE_ATTRIBUTE_CLANG_ENABLE_OBJC_ARC "YES"
        #XCODE_ATTRIBUTE_GCC_GENERATE_DEBUGGING_SYMBOLS NO
        #XCODE_ATTRIBUTE_GCC_GENERATE_DEBUGGING_SYMBOLS[variant=Debug] YES
        #XCODE_ATTRIBUTE_GCC_PREFIX_HEADER ${CMAKE_CURRENT_LIST_DIR}/Precompiled.h
        #XCODE_ATTRIBUTE_GCC_PRECOMPILE_PREFIX_HEADER "YES"
        XCODE_ATTRIBUTE_GCC_C_LANGUAGE_STANDARD "gnu99") 

    if (WITHDEBUG)
        set_target_properties(${PROJECT_NAME} PROPERTIES XCODE_ATTRIBUTE_COPY_PHASE_STRIP NO)
    else ()
        set_target_properties(${PROJECT_NAME} PROPERTIES
            XCODE_ATTRIBUTE_COPY_PHASE_STRIP YES
            XCODE_ATTRIBUTE_COPY_PHASE_STRIP[variant=Debug] NO)
    endif ()

    if (IOS)
        include_directories(${ENGINE_INCLUDE_DIR}/ThirdParty/OpenGL/include)

        set_target_properties(${PROJECT_NAME} PROPERTIES
            XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET ${IOS_DEPLOYMENT_TARGET}
            XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY "1,2") # Universal (iPad + iPhone)

        add_framework(${PROJECT_NAME} Foundation)
        add_framework(${PROJECT_NAME} UIKit)
        add_framework(${PROJECT_NAME} OpenGLES)
        add_framework(${PROJECT_NAME} CoreGraphics)
        add_framework(${PROJECT_NAME} QuartzCore)
    elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        add_framework(${PROJECT_NAME} Carbon)
        add_framework(${PROJECT_NAME} Foundation)
        add_framework(${PROJECT_NAME} AppKit)
        add_framework(${PROJECT_NAME} OpenGL)
        add_framework(${PROJECT_NAME} CoreGraphics)
        add_framework(${PROJECT_NAME} CoreVideo)
    endif ()

    add_framework(${PROJECT_NAME} OpenAL)
elseif (WIN32)
    target_link_libraries(${PROJECT_NAME} ws2_32)

    if (USE_DESKTOP_EGL)
        include(FindOpenGLES3)
        include(FindEGL)

        include_directories(${ENGINE_INCLUDE_DIR}/ThirdParty/OpenGL/include)

        find_library(OPENGLES3_LIBRARY GLESv2)
        find_library(EGL_LIBRARY EGL)

        target_link_libraries(${PROJECT_NAME} ${EGL_LIBRARY} ${OPENGLES3_LIBRARY})
    else ()
        find_package(OpenGL REQUIRED)

        target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
    endif ()

    if (USE_WINDOWS_OPENAL)
        include(FindOpenAL)
    
        target_include_directories(${PROJECT_NAME} PUBLIC ${OPENAL_INCLUDE_DIR})
        target_link_libraries(${PROJECT_NAME} ${OPENAL_LIBRARY})
    else ()
        target_link_libraries(${PROJECT_NAME} dxguid dsound)
    endif ()
endif ()

target_link_libraries(${PROJECT_NAME} 
    zlib
    minizip
    libjpeg
    libpng
    libpvrt
    etcpack_lib
    Etc2CompLib
    libogg
    libvorbis
    jsoncpp
    tinyxml2
    freetype
    Bullet
    HACD
    luasocket
    LuaCpp
    NvTriStrip)

if (USE_LUAJIT)
    target_include_directories(${PROJECT_NAME} PUBLIC ${ENGINE_INCLUDE_DIR}/ThirdParty/luaJIT/src)

    include(FindLuaJIT)
    target_link_libraries(${PROJECT_NAME} ${LUAJIT_LIBRARY})
else ()
    target_include_directories(${PROJECT_NAME} PUBLIC ${ENGINE_INCLUDE_DIR}/ThirdParty/lua)

    target_link_libraries(${PROJECT_NAME} lua)
endif ()

set_target_properties(${PROJECT_NAME} PROPERTIES
    FOLDER "Blueshift"
    PREFIX ""
    #DEBUG_POSTFIX "_d"
    OUTPUT_NAME ${PROJECT_NAME}
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Library/${ENGINE_BUILD_PLATFORM_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Library/${ENGINE_BUILD_PLATFORM_DIR})
