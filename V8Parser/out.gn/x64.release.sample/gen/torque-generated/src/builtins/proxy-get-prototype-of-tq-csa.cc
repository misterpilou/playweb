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

TF_BUILTIN(ProxyGetPrototypeOf, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSProxy> parameter1 = UncheckedCast<JSProxy>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, BoolT, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, JSReceiver> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Context> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Context, JSReceiver> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Object, BoolT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Object, BoolT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Object, BoolT, BoolT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Object> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Object> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Object, Object, BoolT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Object, Object, BoolT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Object, Object, BoolT, BoolT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Object, Object> block28(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Object, Object> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Object, Object> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Object, Object> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Object, Object, Object> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, JSReceiver, HeapObject, JSReceiver, Object, Object, Object> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSProxy> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    CodeStubAssembler(state_).PerformStackCheck(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(JSProxy::kHandlerOffset);
    USE(tmp2);
    TNode<HeapObject>tmp3 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp1, tmp2});
    TNode<JSReceiver> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp3}, &label0);
    ca_.Goto(&block14, tmp0, tmp1, tmp3, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block15, tmp0, tmp1, tmp3);
    }
  }

  if (block11.is_used()) {
    TNode<Context> tmp5;
    TNode<JSProxy> tmp6;
    TNode<BoolT> tmp7;
    ca_.Bind(&block11, &tmp5, &tmp6, &tmp7);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block13, tmp5, tmp6, tmp7, tmp8);
  }

  if (block12.is_used()) {
    TNode<Context> tmp9;
    TNode<JSProxy> tmp10;
    TNode<BoolT> tmp11;
    ca_.Bind(&block12, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12 = ca_.IntPtrConstant(JSProxy::kHandlerOffset);
    USE(tmp12);
    TNode<HeapObject>tmp13 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp10, tmp12});
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = Is_JSReceiver_JSReceiver_OR_Null_0(state_, TNode<Context>{tmp9}, TNode<HeapObject>{tmp13});
    ca_.Goto(&block13, tmp9, tmp10, tmp11, tmp14);
  }

  if (block13.is_used()) {
    TNode<Context> tmp15;
    TNode<JSProxy> tmp16;
    TNode<BoolT> tmp17;
    TNode<BoolT> tmp18;
    ca_.Bind(&block13, &tmp15, &tmp16, &tmp17, &tmp18);
    ca_.Branch(tmp18, &block9, &block10, tmp15, tmp16);
  }

  if (block10.is_used()) {
    TNode<Context> tmp19;
    TNode<JSProxy> tmp20;
    ca_.Bind(&block10, &tmp19, &tmp20);
    CodeStubAssembler(state_).FailAssert("Torque assert 'proxy.handler == Null || Is<JSReceiver>(proxy.handler)' failed", "src/builtins/proxy-get-prototype-of.tq", 19);
  }

  if (block9.is_used()) {
    TNode<Context> tmp21;
    TNode<JSProxy> tmp22;
    ca_.Bind(&block9, &tmp21, &tmp22);
  }

  if (block15.is_used()) {
    TNode<Context> tmp23;
    TNode<JSProxy> tmp24;
    TNode<HeapObject> tmp25;
    ca_.Bind(&block15, &tmp23, &tmp24, &tmp25);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp23}, MessageTemplate::kProxyRevoked, "getPrototypeOf");
  }

  if (block14.is_used()) {
    TNode<Context> tmp26;
    TNode<JSProxy> tmp27;
    TNode<HeapObject> tmp28;
    TNode<JSReceiver> tmp29;
    ca_.Bind(&block14, &tmp26, &tmp27, &tmp28, &tmp29);
    TNode<IntPtrT> tmp30 = ca_.IntPtrConstant(JSProxy::kTargetOffset);
    USE(tmp30);
    TNode<HeapObject>tmp31 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp27, tmp30});
    TNode<JSReceiver> tmp32;
    USE(tmp32);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp32 = GetMethod_2(state_, TNode<Context>{tmp26}, TNode<Object>{tmp29}, "getPrototypeOf", &label0);
    ca_.Goto(&block18, tmp26, tmp27, tmp29, tmp31, tmp29, tmp26, tmp32);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block19, tmp26, tmp27, tmp29, tmp31, tmp29, tmp26);
    }
  }

  if (block19.is_used()) {
    TNode<Context> tmp33;
    TNode<JSProxy> tmp34;
    TNode<JSReceiver> tmp35;
    TNode<HeapObject> tmp36;
    TNode<JSReceiver> tmp37;
    TNode<Context> tmp38;
    ca_.Bind(&block19, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    TNode<Object> tmp39;
    USE(tmp39);
    tmp39 = ObjectGetPrototypeOfImpl_0(state_, TNode<Context>{tmp33}, TNode<Object>{tmp36});
    CodeStubAssembler(state_).Return(tmp39);
  }

  if (block18.is_used()) {
    TNode<Context> tmp40;
    TNode<JSProxy> tmp41;
    TNode<JSReceiver> tmp42;
    TNode<HeapObject> tmp43;
    TNode<JSReceiver> tmp44;
    TNode<Context> tmp45;
    TNode<JSReceiver> tmp46;
    ca_.Bind(&block18, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
    TNode<Object> tmp47;
    USE(tmp47);
    tmp47 = CodeStubAssembler(state_).Call(TNode<Context>{tmp40}, TNode<JSReceiver>{tmp46}, TNode<Object>{tmp42}, TNode<Object>{tmp43});
    TNode<BoolT> tmp48;
    USE(tmp48);
    tmp48 = Is_JSReceiver_JSAny_0(state_, TNode<Context>{tmp40}, TNode<Object>{tmp47});
    TNode<BoolT> tmp49;
    USE(tmp49);
    tmp49 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp48});
    ca_.Branch(tmp49, &block22, &block23, tmp40, tmp41, tmp42, tmp43, tmp46, tmp47, tmp49);
  }

  if (block22.is_used()) {
    TNode<Context> tmp50;
    TNode<JSProxy> tmp51;
    TNode<JSReceiver> tmp52;
    TNode<HeapObject> tmp53;
    TNode<JSReceiver> tmp54;
    TNode<Object> tmp55;
    TNode<BoolT> tmp56;
    ca_.Bind(&block22, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    TNode<Oddball> tmp57;
    USE(tmp57);
    tmp57 = Null_0(state_);
    TNode<BoolT> tmp58;
    USE(tmp58);
    tmp58 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp55}, TNode<HeapObject>{tmp57});
    ca_.Goto(&block24, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp58);
  }

  if (block23.is_used()) {
    TNode<Context> tmp59;
    TNode<JSProxy> tmp60;
    TNode<JSReceiver> tmp61;
    TNode<HeapObject> tmp62;
    TNode<JSReceiver> tmp63;
    TNode<Object> tmp64;
    TNode<BoolT> tmp65;
    ca_.Bind(&block23, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
    TNode<BoolT> tmp66;
    USE(tmp66);
    tmp66 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block24, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66);
  }

  if (block24.is_used()) {
    TNode<Context> tmp67;
    TNode<JSProxy> tmp68;
    TNode<JSReceiver> tmp69;
    TNode<HeapObject> tmp70;
    TNode<JSReceiver> tmp71;
    TNode<Object> tmp72;
    TNode<BoolT> tmp73;
    TNode<BoolT> tmp74;
    ca_.Bind(&block24, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    ca_.Branch(tmp74, &block20, &block21, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72);
  }

  if (block20.is_used()) {
    TNode<Context> tmp75;
    TNode<JSProxy> tmp76;
    TNode<JSReceiver> tmp77;
    TNode<HeapObject> tmp78;
    TNode<JSReceiver> tmp79;
    TNode<Object> tmp80;
    ca_.Bind(&block20, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp75}, MessageTemplate::kProxyGetPrototypeOfInvalid);
  }

  if (block21.is_used()) {
    TNode<Context> tmp81;
    TNode<JSProxy> tmp82;
    TNode<JSReceiver> tmp83;
    TNode<HeapObject> tmp84;
    TNode<JSReceiver> tmp85;
    TNode<Object> tmp86;
    ca_.Bind(&block21, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86);
    TNode<Object> tmp87;
    USE(tmp87);
    tmp87 = ObjectIsExtensibleImpl_0(state_, TNode<Context>{tmp81}, TNode<Object>{tmp84});
    TNode<Oddball> tmp88;
    USE(tmp88);
    tmp88 = True_0(state_);
    TNode<BoolT> tmp89;
    USE(tmp89);
    tmp89 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp87}, TNode<HeapObject>{tmp88});
    ca_.Branch(tmp89, &block32, &block33, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87);
  }

  if (block29.is_used()) {
    TNode<Context> tmp90;
    TNode<JSProxy> tmp91;
    TNode<JSReceiver> tmp92;
    TNode<HeapObject> tmp93;
    TNode<JSReceiver> tmp94;
    TNode<Object> tmp95;
    TNode<Object> tmp96;
    TNode<BoolT> tmp97;
    ca_.Bind(&block29, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97);
    TNode<BoolT> tmp98;
    USE(tmp98);
    tmp98 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block31, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98);
  }

  if (block30.is_used()) {
    TNode<Context> tmp99;
    TNode<JSProxy> tmp100;
    TNode<JSReceiver> tmp101;
    TNode<HeapObject> tmp102;
    TNode<JSReceiver> tmp103;
    TNode<Object> tmp104;
    TNode<Object> tmp105;
    TNode<BoolT> tmp106;
    ca_.Bind(&block30, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106);
    TNode<Oddball> tmp107;
    USE(tmp107);
    tmp107 = False_0(state_);
    TNode<BoolT> tmp108;
    USE(tmp108);
    tmp108 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp105}, TNode<HeapObject>{tmp107});
    ca_.Goto(&block31, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104, tmp105, tmp106, tmp108);
  }

  if (block31.is_used()) {
    TNode<Context> tmp109;
    TNode<JSProxy> tmp110;
    TNode<JSReceiver> tmp111;
    TNode<HeapObject> tmp112;
    TNode<JSReceiver> tmp113;
    TNode<Object> tmp114;
    TNode<Object> tmp115;
    TNode<BoolT> tmp116;
    TNode<BoolT> tmp117;
    ca_.Bind(&block31, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117);
    ca_.Branch(tmp117, &block27, &block28, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115);
  }

  if (block28.is_used()) {
    TNode<Context> tmp118;
    TNode<JSProxy> tmp119;
    TNode<JSReceiver> tmp120;
    TNode<HeapObject> tmp121;
    TNode<JSReceiver> tmp122;
    TNode<Object> tmp123;
    TNode<Object> tmp124;
    ca_.Bind(&block28, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124);
    CodeStubAssembler(state_).FailAssert("Torque assert 'extensibleTarget == True || extensibleTarget == False' failed", "src/builtins/proxy-get-prototype-of.tq", 43);
  }

  if (block27.is_used()) {
    TNode<Context> tmp125;
    TNode<JSProxy> tmp126;
    TNode<JSReceiver> tmp127;
    TNode<HeapObject> tmp128;
    TNode<JSReceiver> tmp129;
    TNode<Object> tmp130;
    TNode<Object> tmp131;
    ca_.Bind(&block27, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131);
  }

  if (block32.is_used()) {
    TNode<Context> tmp132;
    TNode<JSProxy> tmp133;
    TNode<JSReceiver> tmp134;
    TNode<HeapObject> tmp135;
    TNode<JSReceiver> tmp136;
    TNode<Object> tmp137;
    TNode<Object> tmp138;
    ca_.Bind(&block32, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138);
    CodeStubAssembler(state_).Return(tmp137);
  }

  if (block33.is_used()) {
    TNode<Context> tmp139;
    TNode<JSProxy> tmp140;
    TNode<JSReceiver> tmp141;
    TNode<HeapObject> tmp142;
    TNode<JSReceiver> tmp143;
    TNode<Object> tmp144;
    TNode<Object> tmp145;
    ca_.Bind(&block33, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145);
    TNode<Object> tmp146;
    USE(tmp146);
    tmp146 = ObjectGetPrototypeOfImpl_0(state_, TNode<Context>{tmp139}, TNode<Object>{tmp142});
    TNode<BoolT> tmp147;
    USE(tmp147);
    tmp147 = SameValue_0(state_, TNode<Object>{tmp146}, TNode<Object>{tmp144});
    ca_.Branch(tmp147, &block34, &block35, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146);
  }

  if (block34.is_used()) {
    TNode<Context> tmp148;
    TNode<JSProxy> tmp149;
    TNode<JSReceiver> tmp150;
    TNode<HeapObject> tmp151;
    TNode<JSReceiver> tmp152;
    TNode<Object> tmp153;
    TNode<Object> tmp154;
    TNode<Object> tmp155;
    ca_.Bind(&block34, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155);
    CodeStubAssembler(state_).Return(tmp153);
  }

  if (block35.is_used()) {
    TNode<Context> tmp156;
    TNode<JSProxy> tmp157;
    TNode<JSReceiver> tmp158;
    TNode<HeapObject> tmp159;
    TNode<JSReceiver> tmp160;
    TNode<Object> tmp161;
    TNode<Object> tmp162;
    TNode<Object> tmp163;
    ca_.Bind(&block35, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp156}, MessageTemplate::kProxyGetPrototypeOfNonExtensible);
  }
}

}  // namespace internal
}  // namespace v8

