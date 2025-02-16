project(00_testFile VERSION 0.0.1)
juce_add_console_app(00_testFile PRODUCT_NAME "00_testFile")
target_sources(00_testFile PRIVATE main.cpp)
target_compile_definitions(00_testFile PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(00_testFile PRIVATE
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

target_compile_features(00_testFile PRIVATE cxx_std_20)