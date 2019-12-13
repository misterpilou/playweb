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

TF_BUILTIN(ProxyHasProperty, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSProxy> parameter1 = UncheckedCast<JSProxy>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Name> parameter2 = UncheckedCast<Name>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, BoolT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, BoolT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, BoolT, BoolT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, HeapObject> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, HeapObject, JSReceiver> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, JSReceiver, HeapObject> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, JSReceiver, HeapObject, JSReceiver> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, JSReceiver, JSReceiver, JSReceiver, Context> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, JSReceiver, JSReceiver, JSReceiver, Context, JSReceiver> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, JSReceiver, JSReceiver, JSReceiver, Object> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, JSReceiver, JSReceiver, JSReceiver, Object> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSProxy> tmp1;
    TNode<Name> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    CodeStubAssembler(state_).PerformStackCheck(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp3 = ca_.IntPtrConstant(JSProxy::kHandlerOffset);
    USE(tmp3);
    TNode<HeapObject>tmp4 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp1, tmp3});
    TNode<JSReceiver> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp4}, &label0);
    ca_.Goto(&block24, tmp0, tmp1, tmp2, tmp4, tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block25, tmp0, tmp1, tmp2, tmp4);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp6;
    TNode<JSProxy> tmp7;
    TNode<Name> tmp8;
    ca_.Bind(&block4, &tmp6, &tmp7, &tmp8);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsJSProxy(proxy)' failed", "src/builtins/proxy-has-property.tq", 13);
  }

  if (block3.is_used()) {
    TNode<Context> tmp9;
    TNode<JSProxy> tmp10;
    TNode<Name> tmp11;
    ca_.Bind(&block3, &tmp9, &tmp10, &tmp11);
  }

  if (block8.is_used()) {
    TNode<Context> tmp12;
    TNode<JSProxy> tmp13;
    TNode<Name> tmp14;
    ca_.Bind(&block8, &tmp12, &tmp13, &tmp14);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsName(name)' failed", "src/builtins/proxy-has-property.tq", 18);
  }

  if (block7.is_used()) {
    TNode<Context> tmp15;
    TNode<JSProxy> tmp16;
    TNode<Name> tmp17;
    ca_.Bind(&block7, &tmp15, &tmp16, &tmp17);
  }

  if (block12.is_used()) {
    TNode<Context> tmp18;
    TNode<JSProxy> tmp19;
    TNode<Name> tmp20;
    ca_.Bind(&block12, &tmp18, &tmp19, &tmp20);
    CodeStubAssembler(state_).FailAssert("Torque assert '!IsPrivateSymbol(name)' failed", "src/builtins/proxy-has-property.tq", 19);
  }

  if (block11.is_used()) {
    TNode<Context> tmp21;
    TNode<JSProxy> tmp22;
    TNode<Name> tmp23;
    ca_.Bind(&block11, &tmp21, &tmp22, &tmp23);
  }

  if (block21.is_used()) {
    TNode<Context> tmp24;
    TNode<JSProxy> tmp25;
    TNode<Name> tmp26;
    TNode<BoolT> tmp27;
    ca_.Bind(&block21, &tmp24, &tmp25, &tmp26, &tmp27);
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block23, tmp24, tmp25, tmp26, tmp27, tmp28);
  }

  if (block22.is_used()) {
    TNode<Context> tmp29;
    TNode<JSProxy> tmp30;
    TNode<Name> tmp31;
    TNode<BoolT> tmp32;
    ca_.Bind(&block22, &tmp29, &tmp30, &tmp31, &tmp32);
    TNode<IntPtrT> tmp33 = ca_.IntPtrConstant(JSProxy::kHandlerOffset);
    USE(tmp33);
    TNode<HeapObject>tmp34 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp30, tmp33});
    TNode<BoolT> tmp35;
    USE(tmp35);
    tmp35 = Is_JSReceiver_JSReceiver_OR_Null_0(state_, TNode<Context>{tmp29}, TNode<HeapObject>{tmp34});
    ca_.Goto(&block23, tmp29, tmp30, tmp31, tmp32, tmp35);
  }

  if (block23.is_used()) {
    TNode<Context> tmp36;
    TNode<JSProxy> tmp37;
    TNode<Name> tmp38;
    TNode<BoolT> tmp39;
    TNode<BoolT> tmp40;
    ca_.Bind(&block23, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    ca_.Branch(tmp40, &block19, &block20, tmp36, tmp37, tmp38);
  }

  if (block20.is_used()) {
    TNode<Context> tmp41;
    TNode<JSProxy> tmp42;
    TNode<Name> tmp43;
    ca_.Bind(&block20, &tmp41, &tmp42, &tmp43);
    CodeStubAssembler(state_).FailAssert("Torque assert 'proxy.handler == Null || Is<JSReceiver>(proxy.handler)' failed", "src/builtins/proxy-has-property.tq", 25);
  }

  if (block19.is_used()) {
    TNode<Context> tmp44;
    TNode<JSProxy> tmp45;
    TNode<Name> tmp46;
    ca_.Bind(&block19, &tmp44, &tmp45, &tmp46);
  }

  if (block25.is_used()) {
    TNode<Context> tmp47;
    TNode<JSProxy> tmp48;
    TNode<Name> tmp49;
    TNode<HeapObject> tmp50;
    ca_.Bind(&block25, &tmp47, &tmp48, &tmp49, &tmp50);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp47}, MessageTemplate::kProxyRevoked, "has");
  }

  if (block24.is_used()) {
    TNode<Context> tmp51;
    TNode<JSProxy> tmp52;
    TNode<Name> tmp53;
    TNode<HeapObject> tmp54;
    TNode<JSReceiver> tmp55;
    ca_.Bind(&block24, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55);
    TNode<IntPtrT> tmp56 = ca_.IntPtrConstant(JSProxy::kTargetOffset);
    USE(tmp56);
    TNode<HeapObject>tmp57 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp52, tmp56});
    TNode<JSReceiver> tmp58;
    USE(tmp58);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp58 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp57}, &label0);
    ca_.Goto(&block28, tmp51, tmp52, tmp53, tmp55, tmp57, tmp58);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block29, tmp51, tmp52, tmp53, tmp55, tmp57);
    }
  }

  if (block29.is_used()) {
    TNode<Context> tmp59;
    TNode<JSProxy> tmp60;
    TNode<Name> tmp61;
    TNode<JSReceiver> tmp62;
    TNode<HeapObject> tmp63;
    ca_.Bind(&block29, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block28.is_used()) {
    TNode<Context> tmp64;
    TNode<JSProxy> tmp65;
    TNode<Name> tmp66;
    TNode<JSReceiver> tmp67;
    TNode<HeapObject> tmp68;
    TNode<JSReceiver> tmp69;
    ca_.Bind(&block28, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69);
    TNode<JSReceiver> tmp70;
    USE(tmp70);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp70 = GetMethod_2(state_, TNode<Context>{tmp64}, TNode<Object>{tmp67}, "has", &label0);
    ca_.Goto(&block32, tmp64, tmp65, tmp66, tmp67, tmp69, tmp67, tmp64, tmp70);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block33, tmp64, tmp65, tmp66, tmp67, tmp69, tmp67, tmp64);
    }
  }

  if (block33.is_used()) {
    TNode<Context> tmp71;
    TNode<JSProxy> tmp72;
    TNode<Name> tmp73;
    TNode<JSReceiver> tmp74;
    TNode<JSReceiver> tmp75;
    TNode<JSReceiver> tmp76;
    TNode<Context> tmp77;
    ca_.Bind(&block33, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kHasProperty, tmp71, tmp75, tmp73);
  }

  if (block32.is_used()) {
    TNode<Context> tmp78;
    TNode<JSProxy> tmp79;
    TNode<Name> tmp80;
    TNode<JSReceiver> tmp81;
    TNode<JSReceiver> tmp82;
    TNode<JSReceiver> tmp83;
    TNode<Context> tmp84;
    TNode<JSReceiver> tmp85;
    ca_.Bind(&block32, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
    TNode<Object> tmp86;
    USE(tmp86);
    tmp86 = CodeStubAssembler(state_).Call(TNode<Context>{tmp78}, TNode<JSReceiver>{tmp85}, TNode<Object>{tmp81}, TNode<Object>{tmp82}, TNode<Object>{tmp80});
    TNode<BoolT> tmp87;
    USE(tmp87);
    tmp87 = ToBoolean_0(state_, TNode<Object>{tmp86});
    ca_.Branch(tmp87, &block34, &block35, tmp78, tmp79, tmp80, tmp81, tmp82, tmp85, tmp86);
  }

  if (block34.is_used()) {
    TNode<Context> tmp88;
    TNode<JSProxy> tmp89;
    TNode<Name> tmp90;
    TNode<JSReceiver> tmp91;
    TNode<JSReceiver> tmp92;
    TNode<JSReceiver> tmp93;
    TNode<Object> tmp94;
    ca_.Bind(&block34, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94);
    TNode<Oddball> tmp95;
    USE(tmp95);
    tmp95 = True_0(state_);
    CodeStubAssembler(state_).Return(tmp95);
  }

  if (block35.is_used()) {
    TNode<Context> tmp96;
    TNode<JSProxy> tmp97;
    TNode<Name> tmp98;
    TNode<JSReceiver> tmp99;
    TNode<JSReceiver> tmp100;
    TNode<JSReceiver> tmp101;
    TNode<Object> tmp102;
    ca_.Bind(&block35, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102);
    ProxiesCodeStubAssembler(state_).CheckHasTrapResult(TNode<Context>{tmp96}, TNode<JSReceiver>{tmp100}, TNode<JSProxy>{tmp97}, TNode<Name>{tmp98});
    TNode<Oddball> tmp103;
    USE(tmp103);
    tmp103 = False_0(state_);
    CodeStubAssembler(state_).Return(tmp103);
  }
}

}  // namespace internal
}  // namespace v8

