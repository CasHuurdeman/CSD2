project(08_eindopdracht2.0 VERSION 0.0.1)
juce_add_console_app(08_eindopdracht2.0 PRODUCT_NAME "08_eindopdracht2.0")
target_sources(08_eindopdracht2.0 PRIVATE main.cpp melody.cpp UIUtilities.cpp
        synth.cpp organSynth.cpp additiveSynth.cpp
        oscillator.cpp square.cpp sine.cpp saw.cpp
        callback.cpp)
target_compile_definitions(08_eindopdracht2.0 PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR=".")

target_link_libraries(08_eindopdracht2.0
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(08_eindopdracht2.0 PRIVATE cxx_std_20)
