/*
 * config.h
 *
 *  Created on: Jan 31, 2014
 *      Author: david_s5
 */

#ifndef CONFIG_H_
#define CONFIG_H_

// make warnings cross platform
// Use: #pragma message WARN("My message")
#ifdef _MSC_VER
#   define STRINGISE_IMPL(x) #x
#   define STRINGISE(x) STRINGISE_IMPL(x)
#   define FILE_LINE_LINK __FILE__ "(" STRINGISE(__LINE__) ") : "
#   define WARN(exp) (FILE_LINE_LINK "WARNING: " exp)
#else//__GNUC__ - may need other defines for different compilers
#   define WARN(exp) ("WARNING: " exp)
#endif

#if !defined(RELEASE_BUILD) && !defined(DEBUG_BUILD)
#pragma message WARN("Defaulting to Release Build")
#define RELEASE_BUILD
#undef  DEBUG_BUILD
#endif


#if defined(DEBUG_BUILD)
#define DBGMCU_SETTINGS (DBGMCU_CR_DBG_SLEEP|DBGMCU_CR_DBG_STOP|DBGMCU_CR_DBG_STANDBY|DBGMCU_CR_DBG_IWDG_STOP|DBGMCU_CR_DBG_WWDG_STOP)
#else
#define USE_ONLY_PANIC // Define to remove all Logging and only have Panic
#define DBGMCU_SETTINGS (DBGMCU_CR_DBG_IWDG_STOP|DBGMCU_CR_DBG_WWDG_STOP)
#endif
// define to include __FILE__ information within the debug output
#define INCLUDE_FILE_INFO_IN_DEBUG
#define MAX_DEBUG_MESSAGE_LENGTH 120

#define RESET_ON_CFOD                   1       // 1 Will do reset 0 will not
#define MAX_SEC_WAIT_CONNECT            8       // Number of second a TCP, spark will wait
#define MAX_FAILED_CONNECTS             2       // Number of time a connect can fail
#define DEFAULT_SEC_INACTIVITY          0
#define DEFAULT_SEC_NETOPS              20

#endif /* CONFIG_H_ */
