#include "woofer.h"
#include "tweeter.h"

class Speaker{
public:
    Speaker();
    Tweeter aTweeter{2.7f};
    Woofer aWoofer;
};
