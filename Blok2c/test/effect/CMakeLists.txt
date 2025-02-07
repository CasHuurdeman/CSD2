project(01_tremolo VERSION 0.0.1)
juce_add_console_app(01_tremolo PRODUCT_NAME "01_tremolo")
target_sources(01_tremolo PRIVATE main.cpp tremolo.cpp callback.cpp)
target_compile_definitions(01_tremolo PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(01_tremolo PRIVATE
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

target_compile_features(01_tremolo PRIVATE cxx_std_20)
