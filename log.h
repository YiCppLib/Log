#ifndef YICPPLIB_LOG_H
#define YICPPLIB_LOG_H

#include <iostream>

namespace YiCppLib {
	namespace Log {
		typedef struct {
			unsigned int loglvl; 
			const char * logname;
		} LogLvlT;
		static std::ostream bitBucket(0);
	}
}

#define LOG(loglvl) (std::cerr<<"["<<loglvl.logname<<"] ")

#define LOGGER(maxLogLvl) ([](YiCppLib::Log::LogLvlT loglvl) -> std::ostream& { \
        return loglvl.loglvl >= maxLogLvl.loglvl ? LOG(loglvl) : YiCppLib::Log::bitBucket; })

#define LOGLV_DEBUG ((YiCppLib::Log::LogLvlT){.loglvl=0, .logname="DEBUG"})
#define LOGLV_INFO ((YiCppLib::Log::LogLvlT){.loglvl=1, .logname="INFO"})
#define LOGLV_WARN ((YiCppLib::Log::LogLvlT){.loglvl=2, .logname="WARN"})
#define LOGLV_ERR ((YiCppLib::Log::LogLvlT){.loglvl=3, .logname="ERROR"})

/** HOW TO USE
 *
 * Step 1, include this header file
 *
 * Step 2, create a logger object from the LOGGER macro with desired log level
 *         e.g. auto logger = LOGGER(LOGLV_WARN)
 *
 * Step 3, when logging, use the logger object and approprate log level
 *         e.g. logger(LOGLV_INFO) << "File " << filename << " opened" << std::endl;
 *         This log will print if the logger is created with <= LOGLV_INFO,
 *         but won't print if the logger is created with > LOGLV_INFO
 */

#endif
