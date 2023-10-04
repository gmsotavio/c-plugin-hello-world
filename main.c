// main.c
#include <stdio.h>
#include <dlfcn.h>

typedef void (*PluginFunction)();

int main() {
    // Load the plugin library
    void* plugin_handle = dlopen("./plugin.so", RTLD_LAZY);

    if (!plugin_handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    // Get a pointer to the plugin's function
    PluginFunction plugin_function = (PluginFunction)dlsym(plugin_handle, "plugin_function");

    if (!plugin_function) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(plugin_handle);
        return 1;
    }

    // Call the plugin's function
    plugin_function();

    // Unload the plugin library
    dlclose(plugin_handle);

    return 0;
}

