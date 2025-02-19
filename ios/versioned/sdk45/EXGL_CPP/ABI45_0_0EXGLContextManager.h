#pragma once

#include <shared_mutex>
#include "ABI45_0_0EXGLContext.h"

namespace ABI45_0_0expo {
namespace gl_cpp {

using ContextWithLock = std::pair<ABI45_0_0EXGLContext *, std::shared_lock<std::shared_mutex>>;

ABI45_0_0EXGLContextId ContextCreate();
ContextWithLock ContextGet(ABI45_0_0EXGLContextId id);
void ContextDestroy(ABI45_0_0EXGLContextId id);

} // namespace gl_cpp
} // namespace ABI45_0_0expo
