project(08_eindopdracht VERSION 0.0.1)
juce_add_console_app(08_eindopdracht PRODUCT_NAME "08_eindopdracht")
target_sources(08_eindopdracht PRIVATE main.cpp callback.cpp
        effect.cpp circularBuffer.cpp
        delay.cpp waveShaper.cpp
        chorus.cpp
        tremolo.cpp )
target_compile_definitions(08_eindopdracht PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(08_eindopdracht PRIVATE
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

target_compile_features(08_eindopdracht PRIVATE cxx_std_20)