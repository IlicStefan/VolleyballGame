#include "src/Application.h"
#include "src/Configuration.h"

int main() {
    Configuration::initialize();

    Application app;
    app.run(30);

    return 0;
}
