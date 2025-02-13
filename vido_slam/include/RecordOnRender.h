#ifndef RECORD_ON_RENDER_H
#define RECORD_ON_RENDER_H

#include <pangolin/pangolin.h>
#include <string>

// Define your custom RecordOnRender function.
// You can adjust parameters (e.g., window name, file naming, etc.) as needed.
inline void RecordOnRender(const std::string &window_name = "window") {
    pangolin::SaveWindowOnRender(window_name);
}

#endif // RECORD_ON_RENDER_H
