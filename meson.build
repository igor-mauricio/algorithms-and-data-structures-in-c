project('algorithms-and-data-structures-in-c', 'c',
  version : '1.0',
  default_options : ['warning_level=3'])

unity_dep = dependency('unity')

project_src = []
project_inc = []

subdir('src')

algorithms_lib = static_library(meson.project_name(),
sources: project_src,
include_directories: project_inc,
)

algorithms_dep = declare_dependency(
link_with: algorithms_lib,
include_directories: project_inc
)

