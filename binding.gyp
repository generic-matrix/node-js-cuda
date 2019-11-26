{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "main.cpp",'/content/node-js-cuda/test.o'],
    'conditions': [
        [ 'OS=="linux"', {
          'libraries': ['-lcuda','-lcudart'],
          'library_dirs': ['/usr/local/cuda/lib64']
        }]
    ],
    "include_dirs": [
         "<!(node -e \"require('nan')\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}