import json
import os

def get_subdirs_with_cmakesources(dir):
    out_dirs = []
    has_cmakesources = False

    dir_iter = os.scandir(dir)

    for it in dir_iter:
        path = it.path.replace('\\', '/')
        if it.is_file():
            has_cmakesources |= (os.path.basename(path) == 'CMakeSources.cmake')
        else:
            out_dirs.extend(get_subdirs_with_cmakesources(path))
            
    if has_cmakesources:
        out_dirs.append(dir)
    
    return out_dirs


def get_files_recursive(dir, extensions):
    out_files = []
    dir_iter = os.scandir(dir)

    for it in dir_iter:
        path = it.path.replace('\\', '/')

        if it.is_file():
            ext = os.path.splitext(path)[1]
            if ext in extensions:
                out_files.append(path)
        else:
            out_files.extend(get_files_recursive(path, extensions))
    
    return out_files


def remove_prefix(str, prefix_len):
    return str[prefix_len:]


def get_source_groups(dir, source_extensions):
    source_files = get_files_recursive(dir, source_extensions)
    source_groups = {}
    var_prefix = 'SpectralEngine_' + os.path.basename(dir) + '_'

    removed_prefix_size = len(dir) + 1

    for f in source_files:
        file = remove_prefix(f, removed_prefix_size)
        file_dir = os.path.dirname(file)
        group_name = var_prefix + file_dir.replace('/', '_')

        if group_name not in source_groups:
            source_groups[group_name] = { 'dir': file_dir, 'files' : [] }

        source_groups[group_name]['files'].append(file)
    return source_groups


def generate_cmakesources(dir, source_groups):
    cmakesources_path = os.path.join(dir, 'CMakeSources.cmake').replace('\\', '/')
    f = open(cmakesources_path, 'w')

    for group_name, group in source_groups.items():
        f.write('set(' + group_name + '\n')
        for path in group["files"]:
            f.write('\t"' + path + '"\n')
        f.write(')\n\n')
        f.write('source_group("' +group['dir'] + '" FILES ${' + group_name + '})\n\n')


    f.write('set(' + os.path.basename(dir) + '_ALL_SRC\n')
    for group_name in source_groups:
        f.write('\t${' + group_name + '}\n')

    f.write(')\n')
    f.close()


f = open('GenerateCMakeSourcesConfig.json')
config = json.loads(f.read())
f.close()

source_root = config['sourceRootDirPath']

cmakesources_dirs = get_subdirs_with_cmakesources(source_root)

source_extensions = config['sourceExtensions']

for dir in cmakesources_dirs:
    source_groups = get_source_groups(dir, source_extensions)
    generate_cmakesources(dir, source_groups)
