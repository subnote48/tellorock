//
//
//


#ifndef TELLOROCK_APPINIT_H
#define TELLOROCK_APPINIT_H

#ifndef UNICODE
#define UNICODE
#endif

#ifndef NDEBUG
// Production builds should set NDEBUG=1
#define NDEBUG false
#else
#define NDEBUG true
#endif

#ifndef DEBUG
#define DEBUG !NDEBUG
#endif


#include <winsock2.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

//Spdlog
#include <spdlog/spdlog.h>

//ImGui
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

//Boost
#include <boost/asio.hpp>

#include <iostream>
#include <map>
#include <cassert>
#include <string>
#include <thread>
#include <fstream>
#include <codecvt>
#include <ctime>
#include <shlobj.h>
#include <wbemidl.h>
#include <comdef.h>
#include <shellapi.h>
#include <atlbase.h>
#include <atlstr.h>
#include <atltime.h>
#include <vector>
#include <memory>
#include <strsafe.h>
#include <unordered_map>
#include <chrono>
#include <future>
#include <cstdio>
#include <stdexcept>
#include <array>

//Utilities
#include "../Utilities/UtilTello.h"

//Sockets
#include "../Sockets/SocketTello.h"

//Resources
#include "../Resources/resource.h"


#endif //TELLOROCK_APPINIT_H
