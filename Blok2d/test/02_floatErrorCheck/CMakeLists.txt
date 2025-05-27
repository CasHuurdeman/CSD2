project(02_floatErrorCheck VERSION 0.0.1)
juce_add_console_app(02_floatErrorCheck PRODUCT_NAME "02_floatErrorCheck")
target_sources(02_floatErrorCheck PRIVATE main.cpp)
target_compile_definitions(02_floatErrorCheck PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(02_floatErrorCheck PRIVATE
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

target_compile_features(02_floatErrorCheck PRIVATE cxx_std_20)