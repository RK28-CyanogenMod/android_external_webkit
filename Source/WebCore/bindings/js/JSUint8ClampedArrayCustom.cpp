#include "config.h"
#include "JSUint8ClampedArray.h"
#include "JSArrayBufferViewHelper.h"
#include "Uint8ClampedArray.h"
using namespace JSC;
namespace WebCore {
void JSUint8ClampedArray::indexSetter(ExecState* exec, unsigned index, JSValue value) { impl()->set(index, value.toNumber(exec)); }
JSValue toJS(ExecState* exec, JSDOMGlobalObject* globalObject, Uint8ClampedArray* object) { return toJSArrayBufferView<JSUint8ClampedArray>(exec, globalObject, object); }
JSValue JSUint8ClampedArray::set(ExecState* exec) { return setWebGLArrayHelper(exec, impl(), toUint8ClampedArray); }
EncodedJSValue JSC_HOST_CALL JSUint8ClampedArrayConstructor::constructJSUint8ClampedArray(ExecState* exec) { JSUint8ClampedArrayConstructor* c=static_cast<JSUint8ClampedArrayConstructor*>(exec->callee()); RefPtr<Uint8ClampedArray> a=constructArrayBufferView<Uint8ClampedArray,unsigned char>(exec); if (!a.get()) return JSValue::encode(JSValue()); return JSValue::encode(asObject(toJS(exec,c->globalObject(),a.get()))); }
}
