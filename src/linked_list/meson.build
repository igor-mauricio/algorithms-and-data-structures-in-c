tested_src = [
    files('linked_list.c')
]
test_src = [
    files('test/linked_list_test.c')
]

project_src += tested_src
project_inc += include_directories('.')

exe = executable ('linked_list_test', tested_src + test_src, dependencies: unity_dep)
test('linked_list_test', exe)
