project(04_interpolation VERSION 0.0.1)
juce_add_console_app(04_interpolation PRODUCT_NAME "04_interpolation")
target_sources(04_interpolation PRIVATE main.cpp interpolation.cpp)
target_compile_definitions(04_interpolation PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR=".")

target_link_libraries(04_interpolation PRIVATE
        oscillators
        audio

        PUBLIC
        juce::juce_recommended_config_flags
#        juce::juce_recommended_warning_flags
)

target_compile_features(04_interpolation PRIVATE cxx_std_20)