add_rules("mode.release", "mode.debug")
set_languages("c++23")

target("Tetris")
    set_kind("binary")
    add_includedirs("include")
    add_files("src/*.cpp")
