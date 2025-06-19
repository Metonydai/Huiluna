#pragma once

#include "Huiluna/Renderer/OrthographicCamera.h"
#include "Huiluna/Core/Timestep.h"

#include "Huiluna/Events/ApplicationEvent.h"
#include "Huiluna/Events/MouseEvent.h"

namespace Huiluna {

    struct OrthographicCameraBounds
    {
        float Left, Right;
        float Bottom, Top;

        float GetWidth() { return Right - Left; }
        float GetHeight() { return Top - Bottom; }
    };

    class OrthographicCameraController
    {
    public:
        OrthographicCameraController(float aspectRatio, bool rotation = false);

        OrthographicCamera& GetCamera() { return m_Camera; }
        const OrthographicCamera& GetCamera() const { return m_Camera; }

        void OnUpdate(Timestep ts);
        void OnEvent(Event& e);

        float GetZoomLevel() const { return m_ZoomLevel; }
        void SetZoomLevel(float level) { m_ZoomLevel = level; }

        const OrthographicCameraBounds& GetBounds() const { return m_Bounds; }
    private:
        bool OnMouseScrolled(MouseScrolledEvent& e);
        bool OnWindowResized(WindowResizeEvent& e);
    private:
        float m_AspectRatio;
        float m_ZoomLevel = 1.0f;

        OrthographicCameraBounds m_Bounds;
        OrthographicCamera m_Camera;

        bool m_Rotation;

        glm::vec3 m_CameraPosition{ 0.0f };
        float m_CameraRotation = 0.0f;
        float m_CameraTranslationSpeed = 1.0f;
        float m_CameraRotationSpeed = 180.0f;
    };
}