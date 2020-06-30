{
    "targets": [{
        "target_name": "tauro",
        "sources": [ "lib/main.cpp" ],
        'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
        'cflags!': [ '-fno-exceptions' ],
        'cflags_cc!': [ '-fno-exceptions' ],
        'xcode_settings': { 'GCC_ENABLE_CPP_EXCEPTIONS': 'YES', 'CLANG_CXX_LIBRARY': 'libc++', 'MACOSX_DEPLOYMENT_TARGET': '10.7' },
    }],

}