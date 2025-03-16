project(07_pyhtonPlotter2.0 VERSION 0.0.1)
juce_add_console_app(07_pyhtonPlotter2.0 PRODUCT_NAME "07_pyhtonPlotter2.0")
target_sources(07_pyhtonPlotter2.0 PRIVATE main.cpp)
target_compile_definitions(07_pyhtonPlotter2.0 PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(07_pyhtonPlotter2.0 PRIVATE
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

target_compile_features(07_pyhtonPlotter2.0 PRIVATE cxx_std_20)