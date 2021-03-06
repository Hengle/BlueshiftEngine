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

#pragma once

#include "PlatformGeneric.h"

#include <CoreGraphics/CoreGraphics.h>

OBJC_CLASS(NSWindow);

BE_NAMESPACE_BEGIN

class PlatformMacOS : public PlatformGeneric {
public:
    PlatformMacOS();
    
    virtual void            Init() override;
    virtual void            Shutdown() override;

    virtual void            EnableMouse(bool enable) override;

    virtual void            SetMainWindowHandle(void *windowHandle) override;

    virtual void            Quit() override;
    virtual void            Log(const char *msg) override;
    virtual void            Error(const char *msg) override;

    virtual bool            IsCursorLocked() const override;
    virtual bool            LockCursor(bool lock) override;

    virtual void            GetMousePos(Point &pos) const override;
    virtual void            GenerateMouseDeltaEvent() override;

private:
    NSWindow *              window;
    bool                    cursorLocked;
};

BE_NAMESPACE_END
