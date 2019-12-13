#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-bigint-gen.h"
#include "src/builtins/builtins-collections-gen.h"
#include "src/builtins/builtins-constructor-gen.h"
#include "src/builtins/builtins-data-view-gen.h"
#include "src/builtins/builtins-iterator-gen.h"
#include "src/builtins/builtins-promise-gen.h"
#include "src/builtins/builtins-promise.h"
#include "src/builtins/builtins-proxy-gen.h"
#include "src/builtins/builtins-regexp-gen.h"
#include "src/builtins/builtins-string-gen.h"
#include "src/builtins/builtins-typed-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins.h"
#include "src/codegen/code-factory.h"
#include "src/heap/factory-inl.h"
#include "src/objects/arguments.h"
#include "src/objects/bigint.h"
#include "src/objects/elements-kind.h"
#include "src/objects/free-space.h"
#include "src/objects/js-break-iterator.h"
#include "src/objects/js-collator.h"
#include "src/objects/js-date-time-format.h"
#include "src/objects/js-display-names.h"
#include "src/objects/js-generator.h"
#include "src/objects/js-list-format.h"
#include "src/objects/js-locale.h"
#include "src/objects/js-number-format.h"
#include "src/objects/js-objects.h"
#include "src/objects/js-plural-rules.h"
#include "src/objects/js-promise.h"
#include "src/objects/js-regexp-string-iterator.h"
#include "src/objects/js-relative-time-format.h"
#include "src/objects/js-segment-iterator.h"
#include "src/objects/js-segmenter.h"
#include "src/objects/js-weak-refs.h"
#include "src/objects/objects.h"
#include "src/objects/source-text-module.h"
#include "src/objects/stack-frame-info.h"
#include "src/objects/synthetic-module.h"
#include "src/objects/template-objects.h"
#include "torque-generated/src/builtins/array-copywithin-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-filter-tq-csa.h"
#include "torque-generated/src/builtins/array-find-tq-csa.h"
#include "torque-generated/src/builtins/array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/array-foreach-tq-csa.h"
#include "torque-generated/src/builtins/array-isarray-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-lastindexof-tq-csa.h"
#include "torque-generated/src/builtins/array-map-tq-csa.h"
#include "torque-generated/src/builtins/array-of-tq-csa.h"
#include "torque-generated/src/builtins/array-reduce-right-tq-csa.h"
#include "torque-generated/src/builtins/array-reduce-tq-csa.h"
#include "torque-generated/src/builtins/array-reverse-tq-csa.h"
#include "torque-generated/src/builtins/array-shift-tq-csa.h"
#include "torque-generated/src/builtins/array-slice-tq-csa.h"
#include "torque-generated/src/builtins/array-some-tq-csa.h"
#include "torque-generated/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/src/builtins/array-unshift-tq-csa.h"
#include "torque-generated/src/builtins/array-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/bigint-tq-csa.h"
#include "torque-generated/src/builtins/boolean-tq-csa.h"
#include "torque-generated/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/console-tq-csa.h"
#include "torque-generated/src/builtins/data-view-tq-csa.h"
#include "torque-generated/src/builtins/frames-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/growable-fixed-array-tq-csa.h"
#include "torque-generated/src/builtins/internal-coverage-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/math-tq-csa.h"
#include "torque-generated/src/builtins/number-tq-csa.h"
#include "torque-generated/src/builtins/object-fromentries-tq-csa.h"
#include "torque-generated/src/builtins/object-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/promise-constructor-tq-csa.h"
#include "torque-generated/src/builtins/proxy-constructor-tq-csa.h"
#include "torque-generated/src/builtins/proxy-delete-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-get-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-get-prototype-of-tq-csa.h"
#include "torque-generated/src/builtins/proxy-has-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-is-extensible-tq-csa.h"
#include "torque-generated/src/builtins/proxy-prevent-extensions-tq-csa.h"
#include "torque-generated/src/builtins/proxy-revocable-tq-csa.h"
#include "torque-generated/src/builtins/proxy-revoke-tq-csa.h"
#include "torque-generated/src/builtins/proxy-set-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-set-prototype-of-tq-csa.h"
#include "torque-generated/src/builtins/proxy-tq-csa.h"
#include "torque-generated/src/builtins/reflect-tq-csa.h"
#include "torque-generated/src/builtins/regexp-exec-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-all-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-tq-csa.h"
#include "torque-generated/src/builtins/regexp-replace-tq-csa.h"
#include "torque-generated/src/builtins/regexp-search-tq-csa.h"
#include "torque-generated/src/builtins/regexp-source-tq-csa.h"
#include "torque-generated/src/builtins/regexp-split-tq-csa.h"
#include "torque-generated/src/builtins/regexp-test-tq-csa.h"
#include "torque-generated/src/builtins/regexp-tq-csa.h"
#include "torque-generated/src/builtins/string-endswith-tq-csa.h"
#include "torque-generated/src/builtins/string-html-tq-csa.h"
#include "torque-generated/src/builtins/string-iterator-tq-csa.h"
#include "torque-generated/src/builtins/string-pad-tq-csa.h"
#include "torque-generated/src/builtins/string-repeat-tq-csa.h"
#include "torque-generated/src/builtins/string-replaceall-tq-csa.h"
#include "torque-generated/src/builtins/string-slice-tq-csa.h"
#include "torque-generated/src/builtins/string-startswith-tq-csa.h"
#include "torque-generated/src/builtins/string-substring-tq-csa.h"
#include "torque-generated/src/builtins/string-substr-tq-csa.h"
#include "torque-generated/src/builtins/symbol-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-every-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-filter-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-find-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-foreach-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-from-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-of-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-reduce-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-reduceright-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-set-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-slice-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-some-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-sort-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-subarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/src/ic/handler-configuration-tq-csa.h"
#include "torque-generated/src/objects/allocation-site-tq-csa.h"
#include "torque-generated/src/objects/api-callbacks-tq-csa.h"
#include "torque-generated/src/objects/arguments-tq-csa.h"
#include "torque-generated/src/objects/cell-tq-csa.h"
#include "torque-generated/src/objects/code-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/data-handler-tq-csa.h"
#include "torque-generated/src/objects/debug-objects-tq-csa.h"
#include "torque-generated/src/objects/descriptor-array-tq-csa.h"
#include "torque-generated/src/objects/embedder-data-array-tq-csa.h"
#include "torque-generated/src/objects/feedback-cell-tq-csa.h"
#include "torque-generated/src/objects/feedback-vector-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/foreign-tq-csa.h"
#include "torque-generated/src/objects/free-space-tq-csa.h"
#include "torque-generated/src/objects/heap-number-tq-csa.h"
#include "torque-generated/src/objects/heap-object-tq-csa.h"
#include "torque-generated/src/objects/intl-objects-tq-csa.h"
#include "torque-generated/src/objects/js-array-buffer-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/src/objects/js-collection-iterator-tq-csa.h"
#include "torque-generated/src/objects/js-collection-tq-csa.h"
#include "torque-generated/src/objects/js-generator-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"
#include "torque-generated/src/objects/js-promise-tq-csa.h"
#include "torque-generated/src/objects/js-proxy-tq-csa.h"
#include "torque-generated/src/objects/js-regexp-string-iterator-tq-csa.h"
#include "torque-generated/src/objects/js-regexp-tq-csa.h"
#include "torque-generated/src/objects/js-weak-refs-tq-csa.h"
#include "torque-generated/src/objects/literal-objects-tq-csa.h"
#include "torque-generated/src/objects/map-tq-csa.h"
#include "torque-generated/src/objects/microtask-tq-csa.h"
#include "torque-generated/src/objects/module-tq-csa.h"
#include "torque-generated/src/objects/name-tq-csa.h"
#include "torque-generated/src/objects/oddball-tq-csa.h"
#include "torque-generated/src/objects/ordered-hash-table-tq-csa.h"
#include "torque-generated/src/objects/primitive-heap-object-tq-csa.h"
#include "torque-generated/src/objects/promise-tq-csa.h"
#include "torque-generated/src/objects/property-array-tq-csa.h"
#include "torque-generated/src/objects/property-cell-tq-csa.h"
#include "torque-generated/src/objects/prototype-info-tq-csa.h"
#include "torque-generated/src/objects/regexp-match-info-tq-csa.h"
#include "torque-generated/src/objects/script-tq-csa.h"
#include "torque-generated/src/objects/shared-function-info-tq-csa.h"
#include "torque-generated/src/objects/source-text-module-tq-csa.h"
#include "torque-generated/src/objects/stack-frame-info-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"
#include "torque-generated/src/objects/struct-tq-csa.h"
#include "torque-generated/src/objects/synthetic-module-tq-csa.h"
#include "torque-generated/src/objects/template-objects-tq-csa.h"
#include "torque-generated/src/objects/template-tq-csa.h"
#include "torque-generated/src/wasm/wasm-objects-tq-csa.h"
#include "torque-generated/test/torque/test-torque-tq-csa.h"
#include "torque-generated/third_party/v8/builtins/array-sort-tq-csa.h"

namespace v8 {
namespace internal {

TNode<Object> ObjectIsExtensibleImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_object) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, JSReceiver> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, JSReceiver, JSProxy> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_object);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSReceiver> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSReceiver_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<Oddball> tmp7;
    USE(tmp7);
    tmp7 = False_0(state_);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSReceiver> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<JSProxy> tmp13;
    USE(tmp13);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp13 = Cast_JSProxy_0(state_, TNode<HeapObject>{tmp12}, &label0);
    ca_.Goto(&block8, tmp8, tmp9, tmp12, tmp12, tmp13);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp8, tmp9, tmp12, tmp12);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<JSReceiver> tmp16;
    TNode<JSReceiver> tmp17;
    ca_.Bind(&block9, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<Object> tmp18;
    tmp18 = CodeStubAssembler(state_).CallRuntime(Runtime::kObjectIsExtensible, tmp14, tmp16); 
    USE(tmp18);
    ca_.Goto(&block1, tmp14, tmp15, tmp18);
  }

  if (block8.is_used()) {
    TNode<Context> tmp19;
    TNode<Object> tmp20;
    TNode<JSReceiver> tmp21;
    TNode<JSReceiver> tmp22;
    TNode<JSProxy> tmp23;
    ca_.Bind(&block8, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<Object> tmp24;
    tmp24 = CodeStubAssembler(state_).CallBuiltin(Builtins::kProxyIsExtensible, tmp19, tmp23);
    USE(tmp24);
    ca_.Goto(&block1, tmp19, tmp20, tmp24);
  }

  if (block1.is_used()) {
    TNode<Context> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    ca_.Bind(&block1, &tmp25, &tmp26, &tmp27);
    ca_.Goto(&block10, tmp25, tmp26, tmp27);
  }

    TNode<Context> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    ca_.Bind(&block10, &tmp28, &tmp29, &tmp30);
  return TNode<Object>{tmp30};
}

TNode<Object> ObjectPreventExtensionsThrow_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_object) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, JSReceiver> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, JSReceiver, JSProxy> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_object);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSReceiver> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSReceiver_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block1, tmp3, tmp4, tmp4);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Context> tmp10;
    TNode<JSReceiver> tmp11;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<JSProxy> tmp12;
    USE(tmp12);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp12 = Cast_JSProxy_0(state_, TNode<HeapObject>{tmp11}, &label0);
    ca_.Goto(&block8, tmp7, tmp8, tmp11, tmp11, tmp12);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp7, tmp8, tmp11, tmp11);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp13;
    TNode<Object> tmp14;
    TNode<JSReceiver> tmp15;
    TNode<JSReceiver> tmp16;
    ca_.Bind(&block9, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<Object> tmp17;
    tmp17 = CodeStubAssembler(state_).CallRuntime(Runtime::kJSReceiverPreventExtensionsThrow, tmp13, tmp15); 
    USE(tmp17);
    ca_.Goto(&block1, tmp13, tmp14, tmp17);
  }

  if (block8.is_used()) {
    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<JSReceiver> tmp20;
    TNode<JSReceiver> tmp21;
    TNode<JSProxy> tmp22;
    ca_.Bind(&block8, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<Oddball> tmp23;
    USE(tmp23);
    tmp23 = True_0(state_);
    TNode<Object> tmp24;
    tmp24 = CodeStubAssembler(state_).CallBuiltin(Builtins::kProxyPreventExtensions, tmp18, tmp22, tmp23);
    USE(tmp24);
    ca_.Goto(&block1, tmp18, tmp19, tmp20);
  }

  if (block1.is_used()) {
    TNode<Context> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    ca_.Bind(&block1, &tmp25, &tmp26, &tmp27);
    ca_.Goto(&block10, tmp25, tmp26, tmp27);
  }

    TNode<Context> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    ca_.Bind(&block10, &tmp28, &tmp29, &tmp30);
  return TNode<Object>{tmp30};
}

TNode<Object> ObjectPreventExtensionsDontThrow_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_object) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, JSReceiver> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, JSReceiver, JSProxy> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_object);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSReceiver> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSReceiver_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<Oddball> tmp7;
    USE(tmp7);
    tmp7 = False_0(state_);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSReceiver> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<JSProxy> tmp13;
    USE(tmp13);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp13 = Cast_JSProxy_0(state_, TNode<HeapObject>{tmp12}, &label0);
    ca_.Goto(&block8, tmp8, tmp9, tmp12, tmp12, tmp13);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp8, tmp9, tmp12, tmp12);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<JSReceiver> tmp16;
    TNode<JSReceiver> tmp17;
    ca_.Bind(&block9, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<Object> tmp18;
    tmp18 = CodeStubAssembler(state_).CallRuntime(Runtime::kJSReceiverPreventExtensionsDontThrow, tmp14, tmp16); 
    USE(tmp18);
    ca_.Goto(&block1, tmp14, tmp15, tmp18);
  }

  if (block8.is_used()) {
    TNode<Context> tmp19;
    TNode<Object> tmp20;
    TNode<JSReceiver> tmp21;
    TNode<JSReceiver> tmp22;
    TNode<JSProxy> tmp23;
    ca_.Bind(&block8, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<Oddball> tmp24;
    USE(tmp24);
    tmp24 = False_0(state_);
    TNode<Object> tmp25;
    tmp25 = CodeStubAssembler(state_).CallBuiltin(Builtins::kProxyPreventExtensions, tmp19, tmp23, tmp24);
    USE(tmp25);
    ca_.Goto(&block1, tmp19, tmp20, tmp25);
  }

  if (block1.is_used()) {
    TNode<Context> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    ca_.Bind(&block1, &tmp26, &tmp27, &tmp28);
    ca_.Goto(&block10, tmp26, tmp27, tmp28);
  }

    TNode<Context> tmp29;
    TNode<Object> tmp30;
    TNode<Object> tmp31;
    ca_.Bind(&block10, &tmp29, &tmp30, &tmp31);
  return TNode<Object>{tmp31};
}

TNode<Object> ObjectGetPrototypeOfImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_object) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_object);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSReceiver> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = JSReceiverGetPrototypeOf_0(state_, TNode<Context>{tmp0}, TNode<JSReceiver>{tmp2});
    ca_.Goto(&block2, tmp0, tmp1, tmp3);
  }

    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6);
  return TNode<Object>{tmp6};
}

TNode<Object> JSReceiverGetPrototypeOf_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_object) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, JSProxy> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_object);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSProxy> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSProxy_0(state_, TNode<HeapObject>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<JSReceiver> tmp4;
    TNode<JSReceiver> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    TNode<Object> tmp6;
    tmp6 = CodeStubAssembler(state_).CallRuntime(Runtime::kJSReceiverGetPrototypeOf, tmp3, tmp4); 
    USE(tmp6);
    ca_.Goto(&block1, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<JSReceiver> tmp8;
    TNode<JSReceiver> tmp9;
    TNode<JSProxy> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<Object> tmp11;
    tmp11 = CodeStubAssembler(state_).CallBuiltin(Builtins::kProxyGetPrototypeOf, tmp7, tmp10);
    USE(tmp11);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<JSReceiver> tmp13;
    TNode<Object> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<JSReceiver> tmp16;
    TNode<Object> tmp17;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17);
  return TNode<Object>{tmp17};
}

TNode<Object> ObjectSetPrototypeOfThrow_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_object, TNode<HeapObject> p_proto) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, JSReceiver, JSReceiver> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, JSReceiver, JSReceiver, JSProxy> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_object, p_proto);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<HeapObject> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<JSReceiver> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_JSReceiver_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp1, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<HeapObject> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    ca_.Bind(&block5, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    ca_.Goto(&block1, tmp4, tmp5, tmp6, tmp5);
  }

  if (block4.is_used()) {
    TNode<Context> tmp9;
    TNode<Object> tmp10;
    TNode<HeapObject> tmp11;
    TNode<Object> tmp12;
    TNode<Context> tmp13;
    TNode<JSReceiver> tmp14;
    ca_.Bind(&block4, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<JSProxy> tmp15;
    USE(tmp15);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp15 = Cast_JSProxy_0(state_, TNode<HeapObject>{tmp14}, &label0);
    ca_.Goto(&block8, tmp9, tmp10, tmp11, tmp14, tmp14, tmp15);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp9, tmp10, tmp11, tmp14, tmp14);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp16;
    TNode<Object> tmp17;
    TNode<HeapObject> tmp18;
    TNode<JSReceiver> tmp19;
    TNode<JSReceiver> tmp20;
    ca_.Bind(&block9, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Object> tmp21;
    tmp21 = CodeStubAssembler(state_).CallRuntime(Runtime::kJSReceiverSetPrototypeOfThrow, tmp16, tmp19, tmp18); 
    USE(tmp21);
    ca_.Goto(&block1, tmp16, tmp17, tmp18, tmp21);
  }

  if (block8.is_used()) {
    TNode<Context> tmp22;
    TNode<Object> tmp23;
    TNode<HeapObject> tmp24;
    TNode<JSReceiver> tmp25;
    TNode<JSReceiver> tmp26;
    TNode<JSProxy> tmp27;
    ca_.Bind(&block8, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
    TNode<Oddball> tmp28;
    USE(tmp28);
    tmp28 = True_0(state_);
    TNode<Object> tmp29;
    tmp29 = CodeStubAssembler(state_).CallBuiltin(Builtins::kProxySetPrototypeOf, tmp22, tmp27, tmp24, tmp28);
    USE(tmp29);
    ca_.Goto(&block1, tmp22, tmp23, tmp24, tmp25);
  }

  if (block1.is_used()) {
    TNode<Context> tmp30;
    TNode<Object> tmp31;
    TNode<HeapObject> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block1, &tmp30, &tmp31, &tmp32, &tmp33);
    ca_.Goto(&block10, tmp30, tmp31, tmp32, tmp33);
  }

    TNode<Context> tmp34;
    TNode<Object> tmp35;
    TNode<HeapObject> tmp36;
    TNode<Object> tmp37;
    ca_.Bind(&block10, &tmp34, &tmp35, &tmp36, &tmp37);
  return TNode<Object>{tmp37};
}

TNode<Object> ObjectSetPrototypeOfDontThrow_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_object, TNode<HeapObject> p_proto) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, JSReceiver, JSReceiver> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, JSReceiver, JSReceiver, JSProxy> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_object, p_proto);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<HeapObject> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<JSReceiver> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_JSReceiver_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp1, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<HeapObject> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    ca_.Bind(&block5, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<Oddball> tmp9;
    USE(tmp9);
    tmp9 = False_0(state_);
    ca_.Goto(&block1, tmp4, tmp5, tmp6, tmp9);
  }

  if (block4.is_used()) {
    TNode<Context> tmp10;
    TNode<Object> tmp11;
    TNode<HeapObject> tmp12;
    TNode<Object> tmp13;
    TNode<Context> tmp14;
    TNode<JSReceiver> tmp15;
    ca_.Bind(&block4, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<JSProxy> tmp16;
    USE(tmp16);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp16 = Cast_JSProxy_0(state_, TNode<HeapObject>{tmp15}, &label0);
    ca_.Goto(&block8, tmp10, tmp11, tmp12, tmp15, tmp15, tmp16);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp10, tmp11, tmp12, tmp15, tmp15);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<HeapObject> tmp19;
    TNode<JSReceiver> tmp20;
    TNode<JSReceiver> tmp21;
    ca_.Bind(&block9, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<Object> tmp22;
    tmp22 = CodeStubAssembler(state_).CallRuntime(Runtime::kJSReceiverSetPrototypeOfDontThrow, tmp17, tmp20, tmp19); 
    USE(tmp22);
    ca_.Goto(&block1, tmp17, tmp18, tmp19, tmp22);
  }

  if (block8.is_used()) {
    TNode<Context> tmp23;
    TNode<Object> tmp24;
    TNode<HeapObject> tmp25;
    TNode<JSReceiver> tmp26;
    TNode<JSReceiver> tmp27;
    TNode<JSProxy> tmp28;
    ca_.Bind(&block8, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<Oddball> tmp29;
    USE(tmp29);
    tmp29 = False_0(state_);
    TNode<Object> tmp30;
    tmp30 = CodeStubAssembler(state_).CallBuiltin(Builtins::kProxySetPrototypeOf, tmp23, tmp28, tmp25, tmp29);
    USE(tmp30);
    ca_.Goto(&block1, tmp23, tmp24, tmp25, tmp30);
  }

  if (block1.is_used()) {
    TNode<Context> tmp31;
    TNode<Object> tmp32;
    TNode<HeapObject> tmp33;
    TNode<Object> tmp34;
    ca_.Bind(&block1, &tmp31, &tmp32, &tmp33, &tmp34);
    ca_.Goto(&block10, tmp31, tmp32, tmp33, tmp34);
  }

    TNode<Context> tmp35;
    TNode<Object> tmp36;
    TNode<HeapObject> tmp37;
    TNode<Object> tmp38;
    ca_.Bind(&block10, &tmp35, &tmp36, &tmp37, &tmp38);
  return TNode<Object>{tmp38};
}

TF_BUILTIN(CreateObjectWithoutProperties, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NativeContext, Map, FixedArray, Object, Object, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NativeContext, Map, FixedArray, Object, Object, Context, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NativeContext, Map, FixedArray, Object, Object, Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NativeContext, Map, FixedArray, Object, Object, Context, JSReceiver> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NativeContext, Map, FixedArray, Object, JSReceiver, JSFunction> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NativeContext, Map, FixedArray, Object, JSReceiver, JSFunction, JSReceiver, IntPtrT, Map> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NativeContext, Map, FixedArray, Object, JSReceiver, JSFunction, JSReceiver, IntPtrT, Map, PrototypeInfo> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NativeContext, Map, FixedArray, Object, JSReceiver, JSFunction, PrototypeInfo, MaybeObject, MaybeObject> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NativeContext, Map, FixedArray, Object, JSReceiver, JSFunction, PrototypeInfo, MaybeObject, MaybeObject, Oddball> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NativeContext, Map, FixedArray, Object, JSReceiver, JSFunction, PrototypeInfo, MaybeObject, MaybeObject, MaybeObject> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NativeContext, Map, FixedArray, Object, JSReceiver, JSFunction, PrototypeInfo, MaybeObject, MaybeObject, MaybeObject, Map> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NativeContext, Map, FixedArray, Object, JSReceiver, JSFunction> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NativeContext, Map, FixedArray, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NativeContext> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<NativeContext> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<Oddball> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_Null_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp2, ca_.Uninitialized<Map>(), ca_.Uninitialized<FixedArray>(), tmp1, tmp1, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, ca_.Uninitialized<Map>(), ca_.Uninitialized<FixedArray>(), tmp1, tmp1, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<NativeContext> tmp6;
    TNode<Map> tmp7;
    TNode<FixedArray> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    ca_.Bind(&block6, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<JSReceiver> tmp12;
    USE(tmp12);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp12 = Cast_JSReceiver_1(state_, TNode<Context>{tmp4}, TNode<Object>{ca_.UncheckedCast<Object>(tmp9)}, &label0);
    ca_.Goto(&block9, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9, ca_.UncheckedCast<Object>(tmp9), tmp4, tmp12);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9, ca_.UncheckedCast<Object>(tmp9), tmp4);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp13;
    TNode<Object> tmp14;
    TNode<NativeContext> tmp15;
    TNode<Map> tmp16;
    TNode<FixedArray> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Context> tmp20;
    TNode<Oddball> tmp21;
    ca_.Bind(&block5, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<IntPtrT> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::SLOW_OBJECT_WITH_NULL_PROTOTYPE_MAP);
    TNode<Object> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp15}, TNode<IntPtrT>{tmp22});
    TNode<Map> tmp24;
    USE(tmp24);
    tmp24 = UnsafeCast_Map_0(state_, TNode<Context>{tmp13}, TNode<Object>{tmp23});
    TNode<NameDictionary> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).AllocateNameDictionary(NameDictionary::kInitialCapacity);
    ca_.Goto(&block3, tmp13, tmp14, tmp15, tmp24, tmp25, tmp18);
  }

  if (block10.is_used()) {
    TNode<Context> tmp26;
    TNode<Object> tmp27;
    TNode<NativeContext> tmp28;
    TNode<Map> tmp29;
    TNode<FixedArray> tmp30;
    TNode<Object> tmp31;
    TNode<Object> tmp32;
    TNode<Context> tmp33;
    ca_.Bind(&block10, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    ca_.Goto(&block2, tmp26, tmp27, tmp28);
  }

  if (block9.is_used()) {
    TNode<Context> tmp34;
    TNode<Object> tmp35;
    TNode<NativeContext> tmp36;
    TNode<Map> tmp37;
    TNode<FixedArray> tmp38;
    TNode<Object> tmp39;
    TNode<Object> tmp40;
    TNode<Context> tmp41;
    TNode<JSReceiver> tmp42;
    ca_.Bind(&block9, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42);
    TNode<FixedArray> tmp43;
    USE(tmp43);
    tmp43 = kEmptyFixedArray_0(state_);
    TNode<IntPtrT> tmp44;
    USE(tmp44);
    tmp44 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::OBJECT_FUNCTION_INDEX);
    TNode<Object> tmp45;
    USE(tmp45);
    tmp45 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp36}, TNode<IntPtrT>{tmp44});
    TNode<JSFunction> tmp46;
    USE(tmp46);
    tmp46 = UnsafeCast_JSFunction_0(state_, TNode<Context>{tmp34}, TNode<Object>{tmp45});
    TNode<IntPtrT> tmp47 = ca_.IntPtrConstant(JSFunction::kPrototypeOrInitialMapOffset);
    USE(tmp47);
    TNode<HeapObject>tmp48 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp46, tmp47});
    TNode<Map> tmp49;
    USE(tmp49);
    tmp49 = UnsafeCast_Map_0(state_, TNode<Context>{tmp34}, TNode<Object>{tmp48});
    TNode<IntPtrT> tmp50 = ca_.IntPtrConstant(Map::kPrototypeOffset);
    USE(tmp50);
    TNode<HeapObject>tmp51 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp49, tmp50});
    TNode<BoolT> tmp52;
    USE(tmp52);
    tmp52 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp42}, TNode<HeapObject>{tmp51});
    ca_.Branch(tmp52, &block11, &block12, tmp34, tmp35, tmp36, tmp49, tmp43, tmp39, tmp42, tmp46);
  }

  if (block11.is_used()) {
    TNode<Context> tmp53;
    TNode<Object> tmp54;
    TNode<NativeContext> tmp55;
    TNode<Map> tmp56;
    TNode<FixedArray> tmp57;
    TNode<Object> tmp58;
    TNode<JSReceiver> tmp59;
    TNode<JSFunction> tmp60;
    ca_.Bind(&block11, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
    TNode<IntPtrT> tmp61 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp61);
    TNode<Map>tmp62 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp59, tmp61});
    TNode<PrototypeInfo> tmp63;
    USE(tmp63);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp63 = Method_Map_PrototypeInfo_0(state_, TNode<Map>{tmp62}, &label0);
    ca_.Goto(&block13, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp59, tmp61, tmp62, tmp63);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block14, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp59, tmp61, tmp62);
    }
  }

  if (block14.is_used()) {
    TNode<Context> tmp64;
    TNode<Object> tmp65;
    TNode<NativeContext> tmp66;
    TNode<Map> tmp67;
    TNode<FixedArray> tmp68;
    TNode<Object> tmp69;
    TNode<JSReceiver> tmp70;
    TNode<JSFunction> tmp71;
    TNode<JSReceiver> tmp72;
    TNode<IntPtrT> tmp73;
    TNode<Map> tmp74;
    ca_.Bind(&block14, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    ca_.Goto(&block2, tmp64, tmp65, tmp66);
  }

  if (block13.is_used()) {
    TNode<Context> tmp75;
    TNode<Object> tmp76;
    TNode<NativeContext> tmp77;
    TNode<Map> tmp78;
    TNode<FixedArray> tmp79;
    TNode<Object> tmp80;
    TNode<JSReceiver> tmp81;
    TNode<JSFunction> tmp82;
    TNode<JSReceiver> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<Map> tmp85;
    TNode<PrototypeInfo> tmp86;
    ca_.Bind(&block13, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86);
    TNode<IntPtrT> tmp87 = ca_.IntPtrConstant(PrototypeInfo::kObjectCreateMapOffset);
    USE(tmp87);
    TNode<MaybeObject>tmp88 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference{tmp86, tmp87});
    TNode<Oddball> tmp89;
    USE(tmp89);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp89 = Cast_Undefined_0(state_, TNode<MaybeObject>{tmp88}, &label0);
    ca_.Goto(&block17, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp86, tmp88, tmp88, tmp89);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block18, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp86, tmp88, tmp88);
    }
  }

  if (block18.is_used()) {
    TNode<Context> tmp90;
    TNode<Object> tmp91;
    TNode<NativeContext> tmp92;
    TNode<Map> tmp93;
    TNode<FixedArray> tmp94;
    TNode<Object> tmp95;
    TNode<JSReceiver> tmp96;
    TNode<JSFunction> tmp97;
    TNode<PrototypeInfo> tmp98;
    TNode<MaybeObject> tmp99;
    TNode<MaybeObject> tmp100;
    ca_.Bind(&block18, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100);
    TNode<Map> tmp101;
    USE(tmp101);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp101 = WeakToStrong_Map_0(state_, TNode<MaybeObject>{ca_.UncheckedCast<MaybeObject>(tmp99)}, &label0);
    ca_.Goto(&block19, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, ca_.UncheckedCast<MaybeObject>(tmp99), ca_.UncheckedCast<MaybeObject>(tmp99), tmp101);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block20, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, ca_.UncheckedCast<MaybeObject>(tmp99), ca_.UncheckedCast<MaybeObject>(tmp99));
    }
  }

  if (block17.is_used()) {
    TNode<Context> tmp102;
    TNode<Object> tmp103;
    TNode<NativeContext> tmp104;
    TNode<Map> tmp105;
    TNode<FixedArray> tmp106;
    TNode<Object> tmp107;
    TNode<JSReceiver> tmp108;
    TNode<JSFunction> tmp109;
    TNode<PrototypeInfo> tmp110;
    TNode<MaybeObject> tmp111;
    TNode<MaybeObject> tmp112;
    TNode<Oddball> tmp113;
    ca_.Bind(&block17, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113);
    ca_.Goto(&block2, tmp102, tmp103, tmp104);
  }

  if (block20.is_used()) {
    TNode<Context> tmp114;
    TNode<Object> tmp115;
    TNode<NativeContext> tmp116;
    TNode<Map> tmp117;
    TNode<FixedArray> tmp118;
    TNode<Object> tmp119;
    TNode<JSReceiver> tmp120;
    TNode<JSFunction> tmp121;
    TNode<PrototypeInfo> tmp122;
    TNode<MaybeObject> tmp123;
    TNode<MaybeObject> tmp124;
    TNode<MaybeObject> tmp125;
    ca_.Bind(&block20, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125);
    ca_.Goto(&block2, tmp114, tmp115, tmp116);
  }

  if (block19.is_used()) {
    TNode<Context> tmp126;
    TNode<Object> tmp127;
    TNode<NativeContext> tmp128;
    TNode<Map> tmp129;
    TNode<FixedArray> tmp130;
    TNode<Object> tmp131;
    TNode<JSReceiver> tmp132;
    TNode<JSFunction> tmp133;
    TNode<PrototypeInfo> tmp134;
    TNode<MaybeObject> tmp135;
    TNode<MaybeObject> tmp136;
    TNode<MaybeObject> tmp137;
    TNode<Map> tmp138;
    ca_.Bind(&block19, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138);
    ca_.Goto(&block12, tmp126, tmp127, tmp128, tmp138, tmp130, tmp131, tmp132, tmp133);
  }

  if (block12.is_used()) {
    TNode<Context> tmp139;
    TNode<Object> tmp140;
    TNode<NativeContext> tmp141;
    TNode<Map> tmp142;
    TNode<FixedArray> tmp143;
    TNode<Object> tmp144;
    TNode<JSReceiver> tmp145;
    TNode<JSFunction> tmp146;
    ca_.Bind(&block12, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146);
    ca_.Goto(&block3, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144);
  }

  if (block3.is_used()) {
    TNode<Context> tmp147;
    TNode<Object> tmp148;
    TNode<NativeContext> tmp149;
    TNode<Map> tmp150;
    TNode<FixedArray> tmp151;
    TNode<Object> tmp152;
    ca_.Bind(&block3, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152);
    TNode<JSObject> tmp153;
    USE(tmp153);
    tmp153 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map>{tmp150}, TNode<HeapObject>{tmp151});
    CodeStubAssembler(state_).Return(tmp153);
  }

  if (block2.is_used()) {
    TNode<Context> tmp154;
    TNode<Object> tmp155;
    TNode<NativeContext> tmp156;
    ca_.Bind(&block2, &tmp154, &tmp155, &tmp156);
    TNode<Oddball> tmp157;
    USE(tmp157);
    tmp157 = Undefined_0(state_);
    TNode<Object> tmp158;
    tmp158 = CodeStubAssembler(state_).CallRuntime(Runtime::kObjectCreate, tmp154, tmp155, tmp157); 
    USE(tmp158);
    CodeStubAssembler(state_).Return(tmp158);
  }
}

TF_BUILTIN(ObjectIsExtensible, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kObject));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = ObjectIsExtensibleImpl_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(ObjectPreventExtensions, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kObject));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = ObjectPreventExtensionsThrow_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(ObjectGetPrototypeOf, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kObject));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = ObjectGetPrototypeOfImpl_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(ObjectSetPrototypeOf, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kObject));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kProto));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, NativeContext> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, NativeContext, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = RequireObjectCoercible_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, "Object.setPrototypeOf");
    TNode<HeapObject> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = Cast_JSReceiver_OR_Null_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp2}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp2, tmp2, tmp0, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp2, tmp2, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<NativeContext> tmp10;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp5}, MessageTemplate::kProtoObjectOrNull, TNode<Object>{tmp7});
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    TNode<NativeContext> tmp16;
    TNode<HeapObject> tmp17;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<Object> tmp18;
    USE(tmp18);
    tmp18 = ObjectSetPrototypeOfThrow_0(state_, TNode<Context>{tmp11}, TNode<Object>{tmp12}, TNode<HeapObject>{tmp17});
    CodeStubAssembler(state_).Return(tmp18);
  }
}

TNode<Oddball> Cast_Null_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Oddball> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<HeapObject> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp1);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<HeapObject> tmp9;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<Oddball> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_Null_0(state_, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<HeapObject> tmp16;
    TNode<Oddball> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<Oddball> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<Oddball>{tmp20};
}

TNode<Map> WeakToStrong_Map_0(compiler::CodeAssemblerState* state_, TNode<MaybeObject> p_x, compiler::CodeAssemblerLabel* label_ClearedWeakPointer) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<MaybeObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<MaybeObject, MaybeObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<MaybeObject, MaybeObject, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<MaybeObject, Map> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x);

  if (block0.is_used()) {
    TNode<MaybeObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<HeapObject> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).GetHeapObjectAssumeWeak(TNode<MaybeObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<MaybeObject> tmp2;
    TNode<MaybeObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_ClearedWeakPointer);
  }

  if (block3.is_used()) {
    TNode<MaybeObject> tmp4;
    TNode<MaybeObject> tmp5;
    TNode<HeapObject> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    TNode<Map> tmp7;
    USE(tmp7);
    tmp7 = TORQUE_CAST(TNode<HeapObject>{tmp6});
    ca_.Goto(&block5, tmp4, tmp7);
  }

    TNode<MaybeObject> tmp8;
    TNode<Map> tmp9;
    ca_.Bind(&block5, &tmp8, &tmp9);
  return TNode<Map>{tmp9};
}

TNode<HeapObject> Cast_JSReceiver_OR_Null_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<HeapObject> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp1);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<HeapObject> tmp9;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<HeapObject> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_JSReceiver_OR_Null_0(state_, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<HeapObject> tmp16;
    TNode<HeapObject> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<HeapObject> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<HeapObject>{tmp20};
}

}  // namespace internal
}  // namespace v8

