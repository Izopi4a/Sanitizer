
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_SANITIZER_H
#define PHP_SANITIZER_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_SANITIZER_NAME        "sanitizer"
#define PHP_SANITIZER_VERSION     "0.0.1"
#define PHP_SANITIZER_EXTNAME     "sanitizer"
#define PHP_SANITIZER_AUTHOR      ""
#define PHP_SANITIZER_ZEPVERSION  "0.11.2-dd63df153e"
#define PHP_SANITIZER_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(sanitizer)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(sanitizer)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(sanitizer)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(sanitizer, v)
#else
	#define ZEPHIR_GLOBAL(v) (sanitizer_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_sanitizer_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(sanitizer_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(sanitizer_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def sanitizer_globals
#define zend_zephir_globals_def zend_sanitizer_globals

extern zend_module_entry sanitizer_module_entry;
#define phpext_sanitizer_ptr &sanitizer_module_entry

#endif
