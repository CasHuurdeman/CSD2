project(07_eindopdracht VERSION 0.0.1)
juce_add_console_app(07_eindopdracht PRODUCT_NAME "07_eindopdracht")
target_sources(07_eindopdracht PRIVATE main.cpp melody.cpp
        synth.cpp organSynth.cpp
        oscillator.cpp sine.cpp square.cpp saw.cpp
        callback.cpp audioToFile.cpp)
target_compile_definitions(07_eindopdracht PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(07_eindopdracht
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(07_eindopdracht PRIVATE cxx_std_20)
