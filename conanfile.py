from conan import ConanFile
from conan.tools.cmake import cmake_layout


class ODBC_Client(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    options = { 'shared': [ True ] }
    default_options = { 'shared': True }
    generators = "CMakeDeps" #, "CMakeToolchain"

    def requirements(self):
        self.requires("wxwidgets/3.2.6")

    def layout(self):
        cmake_layout(self)
