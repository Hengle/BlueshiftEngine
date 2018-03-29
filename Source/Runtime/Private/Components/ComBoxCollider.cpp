// Copyright(c) 2017 POLYGONTEK
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
// http ://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Precompiled.h"
#include "Physics/Collider.h"
#include "Render/Render.h"
#include "Components/ComTransform.h"
#include "Components/ComBoxCollider.h"
#include "Game/GameWorld.h"

BE_NAMESPACE_BEGIN

OBJECT_DECLARATION("Box Collider", ComBoxCollider, ComCollider)
BEGIN_EVENTS(ComBoxCollider)
END_EVENTS

void ComBoxCollider::RegisterProperties() {
    REGISTER_MIXED_ACCESSOR_PROPERTY("center", "Center", Vec3, GetCenter, SetCenter, Vec3::zero, 
        "", PropertyInfo::SystemUnits | PropertyInfo::EditorFlag);
    REGISTER_MIXED_ACCESSOR_PROPERTY("extents", "Extents", Vec3, GetExtents, SetExtents, Vec3(50.0f), 
        "", PropertyInfo::SystemUnits | PropertyInfo::EditorFlag);
}

ComBoxCollider::ComBoxCollider() {
}

ComBoxCollider::~ComBoxCollider() {
}

void ComBoxCollider::CreateCollider() {
    const ComTransform *transform = GetEntity()->GetTransform();

    Vec3 scaledCenter = transform->GetScale() * center;
    Vec3 scaledExtents = transform->GetScale() * extents;

    collider = colliderManager.AllocUnnamedCollider();
    collider->CreateBox(scaledCenter, scaledExtents);
}

void ComBoxCollider::SetCenter(const Vec3 &center) {
    this->center = center;
    if (collider) {
        colliderManager.ReleaseCollider(collider);

        CreateCollider();
    }
}

void ComBoxCollider::SetExtents(const Vec3 &extents) {
    this->extents = extents;
    if (collider) {
        colliderManager.ReleaseCollider(collider);

        CreateCollider();
    }
}

bool ComBoxCollider::RayIntersection(const Vec3 &start, const Vec3 &dir, bool backFaceCull, float &lastScale) const {
    return false;
}

void ComBoxCollider::DrawGizmos(const SceneView::Parms &sceneView, bool selected) {
    RenderWorld *renderWorld = GetGameWorld()->GetRenderWorld();

    if (selected) {
        ComTransform *transform = GetEntity()->GetTransform();

        if (transform->GetOrigin().DistanceSqr(sceneView.origin) < 20000.0f * 20000.0f) {
            Vec3 scaledCenter = transform->GetScale() * center;
            Vec3 scaledExtents = transform->GetScale() * extents;

            OBB obb(transform->GetTransform() * scaledCenter, scaledExtents + 0.25f, transform->GetAxis());

            renderWorld->SetDebugColor(Color4::orange, Color4::zero);
            renderWorld->DebugOBB(obb, 1.25f);
        }
    }
}

BE_NAMESPACE_END