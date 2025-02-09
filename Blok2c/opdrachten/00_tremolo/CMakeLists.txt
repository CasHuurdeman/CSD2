project(00_tremolo VERSION 0.0.1)
juce_add_console_app(00_tremolo PRODUCT_NAME "00_tremolo")
target_sources(00_tremolo PRIVATE main.cpp tremolo.cpp callback.cpp)
target_compile_definitions(00_tremolo PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR=".")

target_link_libraries(00_tremolo PRIVATE
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

target_compile_features(00_tremolo PRIVATE cxx_std_20)
