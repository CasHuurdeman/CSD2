project(05_pythonPlotter VERSION 0.0.1)
juce_add_console_app(05_pythonPlotter PRODUCT_NAME "05_pythonPlotter")
target_sources(05_pythonPlotter PRIVATE main.cpp)
target_compile_definitions(05_pythonPlotter PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(05_pythonPlotter PRIVATE
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

target_compile_features(05_pythonPlotter PRIVATE cxx_std_20)