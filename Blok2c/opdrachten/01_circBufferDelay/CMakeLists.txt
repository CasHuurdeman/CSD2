project(01_circBufferDelay VERSION 0.0.1)
juce_add_console_app(01_circBufferDelay PRODUCT_NAME "01_circBufferDelay")
target_sources(01_circBufferDelay PRIVATE main.cpp circBuffer.cpp)
target_compile_definitions(01_circBufferDelay PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR=".")

target_link_libraries(01_circBufferDelay PRIVATE
        oscillators
        audio

        PUBLIC
        juce::juce_recommended_config_flags
#        juce::juce_recommended_warning_flags
)

target_compile_features(01_circBufferDelay PRIVATE cxx_std_20)