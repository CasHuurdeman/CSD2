project(06_bufferClass VERSION 0.0.1)
juce_add_console_app(06_bufferClass PRODUCT_NAME "06_bufferClass")
target_sources(06_bufferClass PRIVATE main.cpp callback.cpp effect.cpp tremolo.cpp delay.cpp waveShaper.cpp
#        stereoChorus.cpp
        buffer.cpp)
target_compile_definitions(06_bufferClass PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(06_bufferClass PRIVATE
        oscillators
        audio
        interpolation

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        #        juce::juce_recommended_warning_flags
)

target_compile_features(06_bufferClass PRIVATE cxx_std_20)