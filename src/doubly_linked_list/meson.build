tested_src = [
    files('doubly_linked_list.c')
]
test_src = [
    files('test/doubly_linked_list_test.c')
]

project_src += tested_src
project_inc += include_directories('.')

exe = executable ('doubly_linked_list_test', tested_src + test_src, dependencies: unity_dep)
test('doubly_linked_list_test', exe)
