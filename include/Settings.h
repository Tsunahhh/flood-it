//
// Created by tsuna on 24/09/24.
//

#ifndef SETTINGS_H
#define SETTINGS_H
namespace model {
    struct Settings {
        std::string name{"guest"};
        int width{10};
        int height{10};
        int colors{6};
        int score{0};
    };
}
#endif //SETTINGS_H
