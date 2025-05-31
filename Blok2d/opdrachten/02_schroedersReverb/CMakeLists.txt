project(02_schroedersReverb VERSION 0.0.1)
juce_add_console_app(02_schroedersReverb PRODUCT_NAME "02_schroedersReverb")
target_sources(02_schroedersReverb PRIVATE main.cpp callback.cpp
        effect.cpp circularBuffer.cpp
        filter.cpp combFilter.cpp all-passFilter.cpp
        schroedersReverb.cpp
)
target_compile_definitions(02_schroedersReverb PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(02_schroedersReverb PRIVATE
        interpolation
        oscillators
        audio

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        #        juce::juce_recommended_warning_flags
)

target_compile_features(02_schroedersReverb PRIVATE cxx_std_20)