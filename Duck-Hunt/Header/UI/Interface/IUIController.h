#pragma once

namespace UI
{
    namespace Interface
    {
        class IUIController
        {
        public:
            virtual void Initialize() = 0;
            virtual void Update() = 0;
            virtual void Render() = 0;
            virtual void Show() = 0;

            virtual ~IUIController() { }
        };
    }
}