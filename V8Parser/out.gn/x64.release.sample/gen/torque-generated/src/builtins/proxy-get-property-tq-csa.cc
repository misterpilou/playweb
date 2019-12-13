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

TF_BUILTIN(ProxyGetProperty, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSProxy> parameter1 = UncheckedCast<JSProxy>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Name> parameter2 = UncheckedCast<Name>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  TNode<Smi> parameter4 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<3>()));
  USE(parameter4);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Smi, JSReceiver, HeapObject, HeapObject> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Smi, JSReceiver, HeapObject, HeapObject, Oddball> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Smi, JSReceiver, HeapObject> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Smi, JSReceiver, HeapObject, JSReceiver> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Smi, JSReceiver, JSReceiver, JSReceiver, Context> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Smi, JSReceiver, JSReceiver, JSReceiver, Context, JSReceiver> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3, parameter4);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSProxy> tmp1;
    TNode<Name> tmp2;
    TNode<Object> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    CodeStubAssembler(state_).PerformStackCheck(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp5 = ca_.IntPtrConstant(JSProxy::kHandlerOffset);
    USE(tmp5);
    TNode<HeapObject>tmp6 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp1, tmp5});
    TNode<Oddball> tmp7;
    USE(tmp7);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp7 = Cast_Null_0(state_, TNode<HeapObject>{tmp6}, &label0);
    ca_.Goto(&block15, tmp0, tmp1, tmp2, tmp3, tmp4, ca_.Uninitialized<JSReceiver>(), tmp6, tmp6, tmp7);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp0, tmp1, tmp2, tmp3, tmp4, ca_.Uninitialized<JSReceiver>(), tmp6, tmp6);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<JSProxy> tmp9;
    TNode<Name> tmp10;
    TNode<Object> tmp11;
    TNode<Smi> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedIsNotSmi(name)' failed", "src/builtins/proxy-get-property.tq", 20);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSProxy> tmp14;
    TNode<Name> tmp15;
    TNode<Object> tmp16;
    TNode<Smi> tmp17;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
  }

  if (block8.is_used()) {
    TNode<Context> tmp18;
    TNode<JSProxy> tmp19;
    TNode<Name> tmp20;
    TNode<Object> tmp21;
    TNode<Smi> tmp22;
    ca_.Bind(&block8, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsName(name)' failed", "src/builtins/proxy-get-property.tq", 21);
  }

  if (block7.is_used()) {
    TNode<Context> tmp23;
    TNode<JSProxy> tmp24;
    TNode<Name> tmp25;
    TNode<Object> tmp26;
    TNode<Smi> tmp27;
    ca_.Bind(&block7, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
  }

  if (block12.is_used()) {
    TNode<Context> tmp28;
    TNode<JSProxy> tmp29;
    TNode<Name> tmp30;
    TNode<Object> tmp31;
    TNode<Smi> tmp32;
    ca_.Bind(&block12, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    CodeStubAssembler(state_).FailAssert("Torque assert '!IsPrivateSymbol(name)' failed", "src/builtins/proxy-get-property.tq", 22);
  }

  if (block11.is_used()) {
    TNode<Context> tmp33;
    TNode<JSProxy> tmp34;
    TNode<Name> tmp35;
    TNode<Object> tmp36;
    TNode<Smi> tmp37;
    ca_.Bind(&block11, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
  }

  if (block16.is_used()) {
    TNode<Context> tmp38;
    TNode<JSProxy> tmp39;
    TNode<Name> tmp40;
    TNode<Object> tmp41;
    TNode<Smi> tmp42;
    TNode<JSReceiver> tmp43;
    TNode<HeapObject> tmp44;
    TNode<HeapObject> tmp45;
    ca_.Bind(&block16, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    TNode<IntPtrT> tmp46 = ca_.IntPtrConstant(JSProxy::kTargetOffset);
    USE(tmp46);
    TNode<HeapObject>tmp47 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp39, tmp46});
    TNode<JSReceiver> tmp48;
    USE(tmp48);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp48 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp47}, &label0);
    ca_.Goto(&block19, tmp38, tmp39, tmp40, tmp41, tmp42, ca_.UncheckedCast<JSReceiver>(tmp44), tmp47, tmp48);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block20, tmp38, tmp39, tmp40, tmp41, tmp42, ca_.UncheckedCast<JSReceiver>(tmp44), tmp47);
    }
  }

  if (block15.is_used()) {
    TNode<Context> tmp49;
    TNode<JSProxy> tmp50;
    TNode<Name> tmp51;
    TNode<Object> tmp52;
    TNode<Smi> tmp53;
    TNode<JSReceiver> tmp54;
    TNode<HeapObject> tmp55;
    TNode<HeapObject> tmp56;
    TNode<Oddball> tmp57;
    ca_.Bind(&block15, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp49}, MessageTemplate::kProxyRevoked, "get");
  }

  if (block20.is_used()) {
    TNode<Context> tmp58;
    TNode<JSProxy> tmp59;
    TNode<Name> tmp60;
    TNode<Object> tmp61;
    TNode<Smi> tmp62;
    TNode<JSReceiver> tmp63;
    TNode<HeapObject> tmp64;
    ca_.Bind(&block20, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block19.is_used()) {
    TNode<Context> tmp65;
    TNode<JSProxy> tmp66;
    TNode<Name> tmp67;
    TNode<Object> tmp68;
    TNode<Smi> tmp69;
    TNode<JSReceiver> tmp70;
    TNode<HeapObject> tmp71;
    TNode<JSReceiver> tmp72;
    ca_.Bind(&block19, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    TNode<JSReceiver> tmp73;
    USE(tmp73);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp73 = GetMethod_2(state_, TNode<Context>{tmp65}, TNode<Object>{tmp70}, "get", &label0);
    ca_.Goto(&block23, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp72, tmp70, tmp65, tmp73);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block24, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp72, tmp70, tmp65);
    }
  }

  if (block24.is_used()) {
    TNode<Context> tmp74;
    TNode<JSProxy> tmp75;
    TNode<Name> tmp76;
    TNode<Object> tmp77;
    TNode<Smi> tmp78;
    TNode<JSReceiver> tmp79;
    TNode<JSReceiver> tmp80;
    TNode<JSReceiver> tmp81;
    TNode<Context> tmp82;
    ca_.Bind(&block24, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82);
    TNode<Object> tmp83;
    tmp83 = CodeStubAssembler(state_).CallBuiltin(Builtins::kGetPropertyWithReceiver, tmp74, tmp80, tmp76, tmp77, tmp78);
    USE(tmp83);
    CodeStubAssembler(state_).Return(tmp83);
  }

  if (block23.is_used()) {
    TNode<Context> tmp84;
    TNode<JSProxy> tmp85;
    TNode<Name> tmp86;
    TNode<Object> tmp87;
    TNode<Smi> tmp88;
    TNode<JSReceiver> tmp89;
    TNode<JSReceiver> tmp90;
    TNode<JSReceiver> tmp91;
    TNode<Context> tmp92;
    TNode<JSReceiver> tmp93;
    ca_.Bind(&block23, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93);
    TNode<Object> tmp94;
    USE(tmp94);
    tmp94 = CodeStubAssembler(state_).Call(TNode<Context>{tmp84}, TNode<JSReceiver>{tmp93}, TNode<Object>{tmp89}, TNode<Object>{tmp90}, TNode<Object>{tmp86}, TNode<Object>{tmp87});
    ProxiesCodeStubAssembler(state_).CheckGetSetTrapResult(TNode<Context>{tmp84}, TNode<JSReceiver>{tmp90}, TNode<JSProxy>{tmp85}, TNode<Name>{tmp86}, TNode<Object>{tmp94}, JSProxy::AccessKind::kGet);
    CodeStubAssembler(state_).Return(tmp94);
  }
}

}  // namespace internal
}  // namespace v8

