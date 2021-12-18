#pragma once

#include "plugin.h"

static const CLAP_CONSTEXPR char CLAP_PLUGIN_FACTORY_ID[] = "clap.plugin-factory";

#ifdef __cplusplus
extern "C" {
#endif

// Every methods must be thread-safe.
struct clap_plugin_factory {
   /* Get the number of plugins available.
    * [thread-safe] */
   uint32_t (*get_plugin_count)(void);

   /* Retrieves a plugin descriptor by its index.
    * Returns null in case of error.
    * The descriptor does not need to be freed.
    * [thread-safe] */
   const clap_plugin_descriptor *(*get_plugin_descriptor)(uint32_t index);

   /* Create a clap_plugin by its plugin_id.
    * The returned pointer must be freed by calling plugin->destroy(plugin);
    * The plugin is not allowed to use the host callbacks in the create method.
    * Returns null in case of error.
    * [thread-safe] */
   const clap_plugin *(*create_plugin)(const clap_host *host, const char *plugin_id);
};

#ifdef __cplusplus
}
#endif