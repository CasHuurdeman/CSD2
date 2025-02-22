project(06_stereoChorus VERSION 0.0.1)
juce_add_console_app(06_stereoChorus PRODUCT_NAME "06_stereoChorus")
target_sources(06_stereoChorus PRIVATE main.cpp callback.cpp effect.cpp tremolo.cpp delay.cpp waveShaper.cpp)
target_compile_definitions(06_stereoChorus PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(06_stereoChorus PRIVATE
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

target_compile_features(06_stereoChorus PRIVATE cxx_std_20)