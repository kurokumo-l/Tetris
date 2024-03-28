add_rules("mode.release", "mode.debug")

set_toolchains("clang")
set_languages("c++23")

target("Tetris")
    set_kind("binary")

    add_includedirs("include")
    add_files("src/*.cpp")

    add_syslinks("User32")

target_end()
after_build(function(target)
    local output_dir = target:targetdir()
    local resource_dir = path.join(output_dir, "resource")
    if not os.isdir(resource_dir) then
        os.mkdir(resource_dir)
    end
    local source_file =  "resource/map.txt"
    os.cp(source_file, resource_dir)
end)