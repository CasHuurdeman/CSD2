project(03_filterDaan VERSION 0.0.1)
juce_add_console_app(03_filterDaan PRODUCT_NAME "03_filterDaan")
target_sources(03_filterDaan PRIVATE main.cpp)
target_compile_definitions(03_filterDaan PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(03_filterDaan
        PRIVATE
        oscillators

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(03_filterDaan PRIVATE cxx_std_20)
