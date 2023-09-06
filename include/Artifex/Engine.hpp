#pragma once

#include <Artifex/core/Window.hpp>

#include <Artifex/core/Load.hpp>
#include <Artifex/core/Mix.hpp>
#include <Artifex/core/Render.hpp>
#include <Artifex/core/UI.hpp>

#include <Artifex/types/types.hpp>

#include <cstdint>
#include <unordered_map>
#include <vector>

// TODO: physics
// TODO: optimized rendering

namespace Artifex {

class Engine : public Window {
  public:
    Engine(std::string name, int width = 0, int height = 0);
    ~Engine();

    // Game Loop
    void loop(vec3 clearColor = vec3(), bool (*onUpdate)(float) = nullptr);

    // Update Engine & Window (for manual game loop)
    bool update(vec3 clearColor);

    // Get Current Time (s)
    float time();

    // Get Ratio of Window (width/height)
    inline float ratio() { return (float)width / (float)height; }

    // Add Module
    bool add(std::string name, Module *module, bool enable = true);

    // Resource Loader
    Load load;

    // Basic Renderer
    Render render;

    // UI Renderer
    UI ui;

    // Audio Mixer
    Mix mix;

    // Modules / Add-ons
    std::unordered_map<std::string, Module *> module;

    // Selected Resources
    struct {
        uint16_t shader;
        uint16_t font;
    } current;

  public:
    // Time when frame started
    float now;

    // Duration of Last Frame
    float deltaTime;

    // Resources
    struct {
        std::vector<Shader> shader;
        std::vector<Texture> texture;
        std::vector<GLuint> mesh;
        std::vector<Font> font;

        std::vector<Mix_Music *> music;
        std::vector<Mix_Chunk *> audio;
    } resource;

  private:
    float past;
};

} // namespace Artifex