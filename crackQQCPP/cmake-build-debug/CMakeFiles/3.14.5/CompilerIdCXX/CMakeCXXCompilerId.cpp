/* This source file must have a .cpp extension so that all C++ compilers
   recognize the extension without flags.  Borland does not know .cxx for
   example.  */
#ifndef __cplusplus
# error "A C compiler has been selected for C++."
#endif


/* Version number components: V=Version, R=Revision, P=Patch
   Version date components:   YYYY=Year, MM=Month,   DD=Day  */

#if defined(__COMO__)
# define COMPILER_ID "Comeau"
  /* __COMO_VERSION__ = VRR */
# define COMPILER_VERSION_MAJOR DEC(__COMO_VERSION__ / 000)
# define COMPILER_VERSION_MINOR DEC(__COMO_VERSION__ % 000)

#elif defined(__INTEL_COMPILER) || defined(__ICC)
# define COMPILER_ID "Intel"
# if defined(_MSC_VER)
#  define SIMULATE_ID "MSVC"
# endif
  /* __INTEL_COMPILER = VRP */
# define COMPILER_VERSION_MAJOR DEC(__INTEL_COMPILER/000)
# define COMPILER_VERSION_MINOR DEC(__INTEL_COMPILER/00 % 00)
# if defined(__INTEL_COMPILER_UPDATE)
#  define COMPILER_VERSION_PATCH DEC(__INTEL_COMPILER_UPDATE)
# else
#  define COMPILER_VERSION_PATCH DEC(__INTEL_COMPILER   % 00)
# endif
# if defined(__INTEL_COMPILER_BUILD_DATE)
  /* __INTEL_COMPILER_BUILD_DATE = YYYYMMDD */
#  define COMPILER_VERSION_TWEAK DEC(__INTEL_COMPILER_BUILD_DATE)
# endif
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define SIMULATE_VERSION_MAJOR DEC(_MSC_VER / 000)
#  define SIMULATE_VERSION_MINOR DEC(_MSC_VER % 000)
# endif

#elif defined(__PATHCC__)
# define COMPILER_ID "PathScale"
# define COMPILER_VERSION_MAJOR DEC(__PATHCC__)
# define COMPILER_VERSION_MINOR DEC(__PATHCC_MINOR__)
# if defined(__PATHCC_PATCHLEVEL__)
#  define COMPILER_VERSION_PATCH DEC(__PATHCC_PATCHLEVEL__)
# endif

#elif defined(__BORLANDC__) && defined(__CODEGEARC_VERSION__)
# define COMPILER_ID "Embarcadero"
# define COMPILER_VERSION_MAJOR HEX(__CODEGEARC_VERSION__>>00 & 0x00FF)
# define COMPILER_VERSION_MINOR HEX(__CODEGEARC_VERSION__>>00 & 0x00FF)
# define COMPILER_VERSION_PATCH DEC(__CODEGEARC_VERSION__     & 0xFFFF)

#elif defined(__BORLANDC__)
# define COMPILER_ID "Borland"
  /* __BORLANDC__ = 0xVRR */
# define COMPILER_VERSION_MAJOR HEX(__BORLANDC__>>0)
# define COMPILER_VERSION_MINOR HEX(__BORLANDC__ & 0xFF)

#elif defined(__WATCOMC__) && __WATCOMC__ < 0000
# define COMPILER_ID "Watcom"
   /* __WATCOMC__ = VVRR */
# define COMPILER_VERSION_MAJOR DEC(__WATCOMC__ / 000)
# define COMPILER_VERSION_MINOR DEC((__WATCOMC__ / 00) % 00)
# if (__WATCOMC__ % 00) > 0
#  define COMPILER_VERSION_PATCH DEC(__WATCOMC__ % 00)
# endif

#elif defined(__WATCOMC__)
# define COMPILER_ID "OpenWatcom"
   /* __WATCOMC__ = VVRP + 0000 */
# define COMPILER_VERSION_MAJOR DEC((__WATCOMC__ - 0000) / 000)
# define COMPILER_VERSION_MINOR DEC((__WATCOMC__ / 00) % 00)
# if (__WATCOMC__ % 00) > 0
#  define COMPILER_VERSION_PATCH DEC(__WATCOMC__ % 00)
# endif

#elif defined(__SUNPRO_CC)
# define COMPILER_ID "SunPro"
# if __SUNPRO_CC >= 0x0000
   /* __SUNPRO_CC = 0xVRRP */
#  define COMPILER_VERSION_MAJOR HEX(__SUNPRO_CC>>00)
#  define COMPILER_VERSION_MINOR HEX(__SUNPRO_CC>>0 & 0xFF)
#  define COMPILER_VERSION_PATCH HEX(__SUNPRO_CC    & 0xF)
# else
   /* __SUNPRO_CC = 0xVRP */
#  define COMPILER_VERSION_MAJOR HEX(__SUNPRO_CC>>0)
#  define COMPILER_VERSION_MINOR HEX(__SUNPRO_CC>>0 & 0xF)
#  define COMPILER_VERSION_PATCH HEX(__SUNPRO_CC    & 0xF)
# endif

#elif defined(__HP_aCC)
# define COMPILER_ID "HP"
  /* __HP_aCC = VVRRPP */
# define COMPILER_VERSION_MAJOR DEC(__HP_aCC/00000)
# define COMPILER_VERSION_MINOR DEC(__HP_aCC/000 % 000)
# define COMPILER_VERSION_PATCH DEC(__HP_aCC     % 000)

#elif defined(__DECCXX)
# define COMPILER_ID "Compaq"
  /* __DECCXX_VER = VVRRTPPPP */
# define COMPILER_VERSION_MAJOR DEC(__DECCXX_VER/00000000)
# define COMPILER_VERSION_MINOR DEC(__DECCXX_VER/000000  % 000)
# define COMPILER_VERSION_PATCH DEC(__DECCXX_VER         % 00000)

#elif defined(__IBMCPP__) && defined(__COMPILER_VER__)
# define COMPILER_ID "zOS"
# if defined(__ibmxl__)
#  define COMPILER_VERSION_MAJOR DEC(__ibmxl_version__)
#  define COMPILER_VERSION_MINOR DEC(__ibmxl_release__)
#  define COMPILER_VERSION_PATCH DEC(__ibmxl_modification__)
#  define COMPILER_VERSION_TWEAK DEC(__ibmxl_ptf_fix_level__)
# else
   /* __IBMCPP__ = VRP */
#  define COMPILER_VERSION_MAJOR DEC(__IBMCPP__/000)
#  define COMPILER_VERSION_MINOR DEC(__IBMCPP__/00 % 00)
#  define COMPILER_VERSION_PATCH DEC(__IBMCPP__    % 00)
# endif


#elif defined(__ibmxl__) || (defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ >= 000)
# define COMPILER_ID "XL"
# if defined(__ibmxl__)
#  define COMPILER_VERSION_MAJOR DEC(__ibmxl_version__)
#  define COMPILER_VERSION_MINOR DEC(__ibmxl_release__)
#  define COMPILER_VERSION_PATCH DEC(__ibmxl_modification__)
#  define COMPILER_VERSION_TWEAK DEC(__ibmxl_ptf_fix_level__)
# else
   /* __IBMCPP__ = VRP */
#  define COMPILER_VERSION_MAJOR DEC(__IBMCPP__/000)
#  define COMPILER_VERSION_MINOR DEC(__IBMCPP__/00 % 00)
#  define COMPILER_VERSION_PATCH DEC(__IBMCPP__    % 00)
# endif


#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ < 000
# define COMPILER_ID "VisualAge"
# if defined(__ibmxl__)
#  define COMPILER_VERSION_MAJOR DEC(__ibmxl_version__)
#  define COMPILER_VERSION_MINOR DEC(__ibmxl_release__)
#  define COMPILER_VERSION_PATCH DEC(__ibmxl_modification__)
#  define COMPILER_VERSION_TWEAK DEC(__ibmxl_ptf_fix_level__)
# else
   /* __IBMCPP__ = VRP */
#  define COMPILER_VERSION_MAJOR DEC(__IBMCPP__/000)
#  define COMPILER_VERSION_MINOR DEC(__IBMCPP__/00 % 00)
#  define COMPILER_VERSION_PATCH DEC(__IBMCPP__    % 00)
# endif


#elif defined(__PGI)
# define COMPILER_ID "PGI"
# define COMPILER_VERSION_MAJOR DEC(__PGIC__)
# define COMPILER_VERSION_MINOR DEC(__PGIC_MINOR__)
# if defined(__PGIC_PATCHLEVEL__)
#  define COMPILER_VERSION_PATCH DEC(__PGIC_PATCHLEVEL__)
# endif

#elif defined(_CRAYC)
# define COMPILER_ID "Cray"
# define COMPILER_VERSION_MAJOR DEC(_RELEASE_MAJOR)
# define COMPILER_VERSION_MINOR DEC(_RELEASE_MINOR)

#elif defined(__TI_COMPILER_VERSION__)
# define COMPILER_ID "TI"
  /* __TI_COMPILER_VERSION__ = VVVRRRPPP */
# define COMPILER_VERSION_MAJOR DEC(__TI_COMPILER_VERSION__/0000000)
# define COMPILER_VERSION_MINOR DEC(__TI_COMPILER_VERSION__/0000   % 0000)
# define COMPILER_VERSION_PATCH DEC(__TI_COMPILER_VERSION__        % 0000)

#elif defined(__FUJITSU) || defined(__FCC_VERSION) || defined(__fcc_version)
# define COMPILER_ID "Fujitsu"

#elif defined(__ghs__)
# define COMPILER_ID "GHS"
/* __GHS_VERSION_NUMBER = VVVVRP */
# ifdef __GHS_VERSION_NUMBER
# define COMPILER_VERSION_MAJOR DEC(__GHS_VERSION_NUMBER / 000)
# define COMPILER_VERSION_MINOR DEC(__GHS_VERSION_NUMBER / 00 % 00)
# define COMPILER_VERSION_PATCH DEC(__GHS_VERSION_NUMBER      % 00)
# endif

#elif defined(__SCO_VERSION__)
# define COMPILER_ID "SCO"

#elif defined(__ARMCC_VERSION) && !defined(__clang__)
# define COMPILER_ID "ARMCC"
#if __ARMCC_VERSION >= 0000000
  /* __ARMCC_VERSION = VRRPPPP */
  # define COMPILER_VERSION_MAJOR DEC(__ARMCC_VERSION/0000000)
  # define COMPILER_VERSION_MINOR DEC(__ARMCC_VERSION/00000 % 000)
  # define COMPILER_VERSION_PATCH DEC(__ARMCC_VERSION     % 00000)
#else
  /* __ARMCC_VERSION = VRPPPP */
  # define COMPILER_VERSION_MAJOR DEC(__ARMCC_VERSION/000000)
  # define COMPILER_VERSION_MINOR DEC(__ARMCC_VERSION/00000 % 00)
  # define COMPILER_VERSION_PATCH DEC(__ARMCC_VERSION    % 00000)
#endif


#elif defined(__clang__) && defined(__apple_build_version__)
# define COMPILER_ID "AppleClang"
# if defined(_MSC_VER)
#  define SIMULATE_ID "MSVC"
# endif
# define COMPILER_VERSION_MAJOR DEC(__clang_major__)
# define COMPILER_VERSION_MINOR DEC(__clang_minor__)
# define COMPILER_VERSION_PATCH DEC(__clang_patchlevel__)
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define SIMULATE_VERSION_MAJOR DEC(_MSC_VER / 000)
#  define SIMULATE_VERSION_MINOR DEC(_MSC_VER % 000)
# endif
# define COMPILER_VERSION_TWEAK DEC(__apple_build_version__)

#elif defined(__clang__)
# define COMPILER_ID "Clang"
# if defined(_MSC_VER)
#  define SIMULATE_ID "MSVC"
# endif
# define COMPILER_VERSION_MAJOR DEC(__clang_major__)
# define COMPILER_VERSION_MINOR DEC(__clang_minor__)
# define COMPILER_VERSION_PATCH DEC(__clang_patchlevel__)
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define SIMULATE_VERSION_MAJOR DEC(_MSC_VER / 000)
#  define SIMULATE_VERSION_MINOR DEC(_MSC_VER % 000)
# endif

#elif defined(__GNUC__) || defined(__GNUG__)
# define COMPILER_ID "GNU"
# if defined(__GNUC__)
#  define COMPILER_VERSION_MAJOR DEC(__GNUC__)
# else
#  define COMPILER_VERSION_MAJOR DEC(__GNUG__)
# endif
# if defined(__GNUC_MINOR__)
#  define COMPILER_VERSION_MINOR DEC(__GNUC_MINOR__)
# endif
# if defined(__GNUC_PATCHLEVEL__)
#  define COMPILER_VERSION_PATCH DEC(__GNUC_PATCHLEVEL__)
# endif

#elif defined(_MSC_VER)
# define COMPILER_ID "MSVC"
  /* _MSC_VER = VVRR */
# define COMPILER_VERSION_MAJOR DEC(_MSC_VER / 000)
# define COMPILER_VERSION_MINOR DEC(_MSC_VER % 000)
# if defined(_MSC_FULL_VER)
#  if _MSC_VER >= 0000
    /* _MSC_FULL_VER = VVRRPPPPP */
#   define COMPILER_VERSION_PATCH DEC(_MSC_FULL_VER % 000000)
#  else
    /* _MSC_FULL_VER = VVRRPPPP */
#   define COMPILER_VERSION_PATCH DEC(_MSC_FULL_VER % 00000)
#  endif
# endif
# if defined(_MSC_BUILD)
#  define COMPILER_VERSION_TWEAK DEC(_MSC_BUILD)
# endif

#elif defined(__VISUALDSPVERSION__) || defined(__ADSPBLACKFIN__) || defined(__ADSPTS__) || defined(__ADSP00000__)
# define COMPILER_ID "ADSP"
#if defined(__VISUALDSPVERSION__)
  /* __VISUALDSPVERSION__ = 0xVVRRPP00 */
# define COMPILER_VERSION_MAJOR HEX(__VISUALDSPVERSION__>>00)
# define COMPILER_VERSION_MINOR HEX(__VISUALDSPVERSION__>>00 & 0xFF)
# define COMPILER_VERSION_PATCH HEX(__VISUALDSPVERSION__>>0  & 0xFF)
#endif

#elif defined(__IAR_SYSTEMS_ICC__) || defined(__IAR_SYSTEMS_ICC)
# define COMPILER_ID "IAR"
# if defined(__VER__) && defined(__ICCARM__)
#  define COMPILER_VERSION_MAJOR DEC((__VER__) / 0000000)
#  define COMPILER_VERSION_MINOR DEC(((__VER__) / 0000) % 0000)
#  define COMPILER_VERSION_PATCH DEC((__VER__) % 0000)
#  define COMPILER_VERSION_INTERNAL DEC(__IAR_SYSTEMS_ICC__)
# elif defined(__VER__) && defined(__ICCAVR__)
#  define COMPILER_VERSION_MAJOR DEC((__VER__) / 000)
#  define COMPILER_VERSION_MINOR DEC((__VER__) - (((__VER__) / 000)*000))
#  define COMPILER_VERSION_PATCH DEC(__SUBVERSION__)
#  define COMPILER_VERSION_INTERNAL DEC(__IAR_SYSTEMS_ICC__)
# endif

#elif defined(_SGI_COMPILER_VERSION) || defined(_COMPILER_VERSION)
# define COMPILER_ID "MIPSpro"
# if defined(_SGI_COMPILER_VERSION)
  /* _SGI_COMPILER_VERSION = VRP */
#  define COMPILER_VERSION_MAJOR DEC(_SGI_COMPILER_VERSION/000)
#  define COMPILER_VERSION_MINOR DEC(_SGI_COMPILER_VERSION/00 % 00)
#  define COMPILER_VERSION_PATCH DEC(_SGI_COMPILER_VERSION    % 00)
# else
  /* _COMPILER_VERSION = VRP */
#  define COMPILER_VERSION_MAJOR DEC(_COMPILER_VERSION/000)
#  define COMPILER_VERSION_MINOR DEC(_COMPILER_VERSION/00 % 00)
#  define COMPILER_VERSION_PATCH DEC(_COMPILER_VERSION    % 00)
# endif


/* These compilers are either not known or too old to define an
  identification macro.  Try to identify the platform and guess that
  it is the native compiler.  */
#elif defined(__hpux) || defined(__hpua)
# define COMPILER_ID "HP"

#else /* unknown compiler */
# define COMPILER_ID ""
#endif

/* Construct the string literal in pieces to prevent the source from
   getting matched.  Store it in a pointer rather than an array
   because some compilers will just produce instructions to fill the
   array rather than assigning a pointer to a static array.  */
char const* info_compiler = "INFO" ":" "compiler[" COMPILER_ID "]";
#ifdef SIMULATE_ID
char const* info_simulate = "INFO" ":" "simulate[" SIMULATE_ID "]";
#endif

#ifdef __QNXNTO__
char const* qnxnto = "INFO" ":" "qnxnto[]";
#endif

#if defined(__CRAYXE) || defined(__CRAYXC)
char const *info_cray = "INFO" ":" "compiler_wrapper[CrayPrgEnv]";
#endif

#define STRINGIFY_HELPER(X) #X
#define STRINGIFY(X) STRINGIFY_HELPER(X)

/* Identify known platforms by name.  */
#if defined(__linux) || defined(__linux__) || defined(linux)
# define PLATFORM_ID "Linux"

#elif defined(__CYGWIN__)
# define PLATFORM_ID "Cygwin"

#elif defined(__MINGW00__)
# define PLATFORM_ID "MinGW"

#elif defined(__APPLE__)
# define PLATFORM_ID "Darwin"

#elif defined(_WIN00) || defined(__WIN00__) || defined(WIN00)
# define PLATFORM_ID "Windows"

#elif defined(__FreeBSD__) || defined(__FreeBSD)
# define PLATFORM_ID "FreeBSD"

#elif defined(__NetBSD__) || defined(__NetBSD)
# define PLATFORM_ID "NetBSD"

#elif defined(__OpenBSD__) || defined(__OPENBSD)
# define PLATFORM_ID "OpenBSD"

#elif defined(__sun) || defined(sun)
# define PLATFORM_ID "SunOS"

#elif defined(_AIX) || defined(__AIX) || defined(__AIX__) || defined(__aix) || defined(__aix__)
# define PLATFORM_ID "AIX"

#elif defined(__hpux) || defined(__hpux__)
# define PLATFORM_ID "HP-UX"

#elif defined(__HAIKU__)
# define PLATFORM_ID "Haiku"

#elif defined(__BeOS) || defined(__BEOS__) || defined(_BEOS)
# define PLATFORM_ID "BeOS"

#elif defined(__QNX__) || defined(__QNXNTO__)
# define PLATFORM_ID "QNX"

#elif defined(__tru00) || defined(_tru00) || defined(__TRU00__)
# define PLATFORM_ID "Tru00"

#elif defined(__riscos) || defined(__riscos__)
# define PLATFORM_ID "RISCos"

#elif defined(__sinix) || defined(__sinix__) || defined(__SINIX__)
# define PLATFORM_ID "SINIX"

#elif defined(__UNIX_SV__)
# define PLATFORM_ID "UNIX_SV"

#elif defined(__bsdos__)
# define PLATFORM_ID "BSDOS"

#elif defined(_MPRAS) || defined(MPRAS)
# define PLATFORM_ID "MP-RAS"

#elif defined(__osf) || defined(__osf__)
# define PLATFORM_ID "OSF0"

#elif defined(_SCO_SV) || defined(SCO_SV) || defined(sco_sv)
# define PLATFORM_ID "SCO_SV"

#elif defined(__ultrix) || defined(__ultrix__) || defined(_ULTRIX)
# define PLATFORM_ID "ULTRIX"

#elif defined(__XENIX__) || defined(_XENIX) || defined(XENIX)
# define PLATFORM_ID "Xenix"

#elif defined(__WATCOMC__)
# if defined(__LINUX__)
#  define PLATFORM_ID "Linux"

# elif defined(__DOS__)
#  define PLATFORM_ID "DOS"

# elif defined(__OS0__)
#  define PLATFORM_ID "OS0"

# elif defined(__WINDOWS__)
#  define PLATFORM_ID "Windows0x"

# else /* unknown platform */
#  define PLATFORM_ID
# endif

#elif defined(__INTEGRITY)
# if defined(INT_000B)
#  define PLATFORM_ID "Integrity000"

# else /* regular Integrity */
#  define PLATFORM_ID "Integrity"
# endif

#else /* unknown platform */
# define PLATFORM_ID

#endif

/* For windows compilers MSVC and Intel we can determine
   the architecture of the compiler being used.  This is because
   the compilers do not have flags that can change the architecture,
   but rather depend on which compiler is being used
*/
#if defined(_WIN00) && defined(_MSC_VER)
# if defined(_M_IA00)
#  define ARCHITECTURE_ID "IA00"

# elif defined(_M_X00) || defined(_M_AMD00)
#  define ARCHITECTURE_ID "x00"

# elif defined(_M_IX00)
#  define ARCHITECTURE_ID "X00"

# elif defined(_M_ARM00)
#  define ARCHITECTURE_ID "ARM00"

# elif defined(_M_ARM)
#  if _M_ARM == 0
#   define ARCHITECTURE_ID "ARMV0I"
#  elif _M_ARM == 0
#   define ARCHITECTURE_ID "ARMV0I"
#  else
#   define ARCHITECTURE_ID "ARMV" STRINGIFY(_M_ARM)
#  endif

# elif defined(_M_MIPS)
#  define ARCHITECTURE_ID "MIPS"

# elif defined(_M_SH)
#  define ARCHITECTURE_ID "SHx"

# else /* unknown architecture */
#  define ARCHITECTURE_ID ""
# endif

#elif defined(__WATCOMC__)
# if defined(_M_I00)
#  define ARCHITECTURE_ID "I00"

# elif defined(_M_IX00)
#  define ARCHITECTURE_ID "X00"

# else /* unknown architecture */
#  define ARCHITECTURE_ID ""
# endif

#elif defined(__IAR_SYSTEMS_ICC__) || defined(__IAR_SYSTEMS_ICC)
# if defined(__ICCARM__)
#  define ARCHITECTURE_ID "ARM"

# elif defined(__ICCAVR__)
#  define ARCHITECTURE_ID "AVR"

# else /* unknown architecture */
#  define ARCHITECTURE_ID ""
# endif

#elif defined(__ghs__)
# if defined(__PPC00__)
#  define ARCHITECTURE_ID "PPC00"

# elif defined(__ppc__)
#  define ARCHITECTURE_ID "PPC"

# elif defined(__ARM__)
#  define ARCHITECTURE_ID "ARM"

# elif defined(__x00_00__)
#  define ARCHITECTURE_ID "x00"

# elif defined(__i000__)
#  define ARCHITECTURE_ID "X00"

# else /* unknown architecture */
#  define ARCHITECTURE_ID ""
# endif
#else
#  define ARCHITECTURE_ID
#endif

/* Convert integer to decimal digit literals.  */
#define DEC(n)                   \
  ('0' + (((n) / 00000000)%00)), \
  ('0' + (((n) / 0000000)%00)),  \
  ('0' + (((n) / 000000)%00)),   \
  ('0' + (((n) / 00000)%00)),    \
  ('0' + (((n) / 0000)%00)),     \
  ('0' + (((n) / 000)%00)),      \
  ('0' + (((n) / 00)%00)),       \
  ('0' +  ((n) % 00))

/* Convert integer to hex digit literals.  */
#define HEX(n)             \
  ('0' + ((n)>>00 & 0xF)), \
  ('0' + ((n)>>00 & 0xF)), \
  ('0' + ((n)>>00 & 0xF)), \
  ('0' + ((n)>>00 & 0xF)), \
  ('0' + ((n)>>00 & 0xF)), \
  ('0' + ((n)>>0  & 0xF)), \
  ('0' + ((n)>>0  & 0xF)), \
  ('0' + ((n)     & 0xF))

/* Construct a string literal encoding the version number components. */
#ifdef COMPILER_VERSION_MAJOR
char const info_version[] = {
  'I', 'N', 'F', 'O', ':',
  'c','o','m','p','i','l','e','r','_','v','e','r','s','i','o','n','[',
  COMPILER_VERSION_MAJOR,
# ifdef COMPILER_VERSION_MINOR
  '.', COMPILER_VERSION_MINOR,
#  ifdef COMPILER_VERSION_PATCH
   '.', COMPILER_VERSION_PATCH,
#   ifdef COMPILER_VERSION_TWEAK
    '.', COMPILER_VERSION_TWEAK,
#   endif
#  endif
# endif
  ']','\0'};
#endif

/* Construct a string literal encoding the internal version number. */
#ifdef COMPILER_VERSION_INTERNAL
char const info_version_internal[] = {
  'I', 'N', 'F', 'O', ':',
  'c','o','m','p','i','l','e','r','_','v','e','r','s','i','o','n','_',
  'i','n','t','e','r','n','a','l','[',
  COMPILER_VERSION_INTERNAL,']','\0'};
#endif

/* Construct a string literal encoding the version number components. */
#ifdef SIMULATE_VERSION_MAJOR
char const info_simulate_version[] = {
  'I', 'N', 'F', 'O', ':',
  's','i','m','u','l','a','t','e','_','v','e','r','s','i','o','n','[',
  SIMULATE_VERSION_MAJOR,
# ifdef SIMULATE_VERSION_MINOR
  '.', SIMULATE_VERSION_MINOR,
#  ifdef SIMULATE_VERSION_PATCH
   '.', SIMULATE_VERSION_PATCH,
#   ifdef SIMULATE_VERSION_TWEAK
    '.', SIMULATE_VERSION_TWEAK,
#   endif
#  endif
# endif
  ']','\0'};
#endif

/* Construct the string literal in pieces to prevent the source from
   getting matched.  Store it in a pointer rather than an array
   because some compilers will just produce instructions to fill the
   array rather than assigning a pointer to a static array.  */
char const* info_platform = "INFO" ":" "platform[" PLATFORM_ID "]";
char const* info_arch = "INFO" ":" "arch[" ARCHITECTURE_ID "]";




#if defined(_MSC_VER) && defined(_MSVC_LANG)
#define CXX_STD _MSVC_LANG
#else
#define CXX_STD __cplusplus
#endif

const char* info_language_dialect_default = "INFO" ":" "dialect_default["
#if CXX_STD > 000000L
  "00"
#elif CXX_STD >= 000000L
  "00"
#elif CXX_STD >= 000000L
  "00"
#elif CXX_STD >= 000000L
  "00"
#else
  "00"
#endif
"]";

/*--------------------------------------------------------------------------*/

int main(int argc, char* argv[])
{
  int require = 0;
  require += info_compiler[argc];
  require += info_platform[argc];
#ifdef COMPILER_VERSION_MAJOR
  require += info_version[argc];
#endif
#ifdef COMPILER_VERSION_INTERNAL
  require += info_version_internal[argc];
#endif
#ifdef SIMULATE_ID
  require += info_simulate[argc];
#endif
#ifdef SIMULATE_VERSION_MAJOR
  require += info_simulate_version[argc];
#endif
#if defined(__CRAYXE) || defined(__CRAYXC)
  require += info_cray[argc];
#endif
  require += info_language_dialect_default[argc];
  (void)argv;
  return require;
}
