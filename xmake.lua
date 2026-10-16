add_rules("mode.debug", "mode.release")

set_languages("c++20")

add_requires("spdlog")

target("XSMALL")
set_kind("binary")
add_files("src/*.cpp")
add_includedirs("include")
add_packages("spdlog")
