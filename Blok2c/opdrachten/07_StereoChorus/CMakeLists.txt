project(07_StereoChorus VERSION 0.0.1)
juce_add_console_app(07_StereoChorus PRODUCT_NAME "07_StereoChorus")
target_sources(07_StereoChorus PRIVATE main.cpp callback.cpp
        effect.cpp circularBuffer.cpp
        delay.cpp waveShaper.cpp
        stereoChorus.cpp chorus.cpp
        LFO.cpp tremolo.cpp )
target_compile_definitions(07_StereoChorus PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(07_StereoChorus PRIVATE
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

target_compile_features(07_StereoChorus PRIVATE cxx_std_20)