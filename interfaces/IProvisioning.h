/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include "Module.h"

namespace WPEFramework {
namespace Exchange {

    struct EXTERNAL IProvisioning : virtual public Core::IUnknown {
        enum { ID = ID_PROVISIONING };

        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_PROVISIONING_NOTIFICATION };

            // Signal changes on the subscribed namespace..
            virtual void Provisioned(RPC::IStringIterator* labels) = 0;
        };

        virtual void Register(IProvisioning::INotification* provisioning) = 0;
        virtual void Unregister(IProvisioning::INotification* provisioning) = 0;
        virtual uint32_t DRMId (const string& label /* @in */, string& drmId /* @out */) const = 0;
        virtual uint32_t DeviceId (string& deviceId /* @out */) const = 0;
    };
}
}

