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

void CallThrowTypeErrorIfStrict_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, MessageTemplate p_message) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).SmiConstant(p_message);
    TNode<Oddball> tmp2;
    USE(tmp2);
    tmp2 = Null_0(state_);
    TNode<Oddball> tmp3;
    USE(tmp3);
    tmp3 = Null_0(state_);
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowTypeErrorIfStrict, tmp0, tmp1, tmp2, tmp3);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Context> tmp5;
    ca_.Bind(&block2, &tmp5);
}

TF_BUILTIN(ProxySetProperty, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSProxy> parameter1 = UncheckedCast<JSProxy>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Name> parameter2 = UncheckedCast<Name>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  TNode<Object> parameter4 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<3>()));
  USE(parameter4);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object, Name, Name, Name> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object, Name, Name, Name, Symbol> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object, Name, BoolT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object, Name, BoolT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object, Name, BoolT, BoolT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object, Name> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object, Name> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object, Name, HeapObject> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object, Name, HeapObject, JSReceiver> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object, Name, JSReceiver, JSReceiver, JSReceiver, Context> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object, Name, JSReceiver, JSReceiver, JSReceiver, Context, JSReceiver> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object, Name, JSReceiver, JSReceiver, JSReceiver, Object> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Object, Object, Name, JSReceiver, JSReceiver, JSReceiver, Object> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3, parameter4);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSProxy> tmp1;
    TNode<Name> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<Symbol> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_PrivateSymbol_1(state_, TNode<HeapObject>{tmp2}, &label0);
    ca_.Goto(&block11, tmp0, tmp1, tmp2, tmp3, tmp4, ca_.Uninitialized<Name>(), tmp2, tmp2, tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp0, tmp1, tmp2, tmp3, tmp4, ca_.Uninitialized<Name>(), tmp2, tmp2);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp6;
    TNode<JSProxy> tmp7;
    TNode<Name> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    ca_.Bind(&block4, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedIsNotSmi(name)' failed", "src/builtins/proxy-set-property.tq", 25);
  }

  if (block3.is_used()) {
    TNode<Context> tmp11;
    TNode<JSProxy> tmp12;
    TNode<Name> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
  }

  if (block8.is_used()) {
    TNode<Context> tmp16;
    TNode<JSProxy> tmp17;
    TNode<Name> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block8, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsName(name)' failed", "src/builtins/proxy-set-property.tq", 26);
  }

  if (block7.is_used()) {
    TNode<Context> tmp21;
    TNode<JSProxy> tmp22;
    TNode<Name> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block7, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
  }

  if (block12.is_used()) {
    TNode<Context> tmp26;
    TNode<JSProxy> tmp27;
    TNode<Name> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    TNode<Name> tmp31;
    TNode<Name> tmp32;
    TNode<Name> tmp33;
    ca_.Bind(&block12, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34 = ca_.IntPtrConstant(JSProxy::kHandlerOffset);
    USE(tmp34);
    TNode<HeapObject>tmp35 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp27, tmp34});
    TNode<JSReceiver> tmp36;
    USE(tmp36);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp36 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp35}, &label0);
    ca_.Goto(&block24, tmp26, tmp27, tmp28, tmp29, tmp30, ca_.UncheckedCast<Name>(tmp32), tmp35, tmp36);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block25, tmp26, tmp27, tmp28, tmp29, tmp30, ca_.UncheckedCast<Name>(tmp32), tmp35);
    }
  }

  if (block11.is_used()) {
    TNode<Context> tmp37;
    TNode<JSProxy> tmp38;
    TNode<Name> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    TNode<Name> tmp42;
    TNode<Name> tmp43;
    TNode<Name> tmp44;
    TNode<Symbol> tmp45;
    ca_.Bind(&block11, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    CallThrowTypeErrorIfStrict_0(state_, TNode<Context>{tmp37}, MessageTemplate::kProxyPrivate);
    TNode<Oddball> tmp46;
    USE(tmp46);
    tmp46 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp46);
  }

  if (block21.is_used()) {
    TNode<Context> tmp47;
    TNode<JSProxy> tmp48;
    TNode<Name> tmp49;
    TNode<Object> tmp50;
    TNode<Object> tmp51;
    TNode<Name> tmp52;
    TNode<BoolT> tmp53;
    ca_.Bind(&block21, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    TNode<BoolT> tmp54;
    USE(tmp54);
    tmp54 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block23, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54);
  }

  if (block22.is_used()) {
    TNode<Context> tmp55;
    TNode<JSProxy> tmp56;
    TNode<Name> tmp57;
    TNode<Object> tmp58;
    TNode<Object> tmp59;
    TNode<Name> tmp60;
    TNode<BoolT> tmp61;
    ca_.Bind(&block22, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61);
    TNode<IntPtrT> tmp62 = ca_.IntPtrConstant(JSProxy::kHandlerOffset);
    USE(tmp62);
    TNode<HeapObject>tmp63 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp56, tmp62});
    TNode<BoolT> tmp64;
    USE(tmp64);
    tmp64 = Is_JSReceiver_JSReceiver_OR_Null_0(state_, TNode<Context>{tmp55}, TNode<HeapObject>{tmp63});
    ca_.Goto(&block23, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp64);
  }

  if (block23.is_used()) {
    TNode<Context> tmp65;
    TNode<JSProxy> tmp66;
    TNode<Name> tmp67;
    TNode<Object> tmp68;
    TNode<Object> tmp69;
    TNode<Name> tmp70;
    TNode<BoolT> tmp71;
    TNode<BoolT> tmp72;
    ca_.Bind(&block23, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    ca_.Branch(tmp72, &block19, &block20, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70);
  }

  if (block20.is_used()) {
    TNode<Context> tmp73;
    TNode<JSProxy> tmp74;
    TNode<Name> tmp75;
    TNode<Object> tmp76;
    TNode<Object> tmp77;
    TNode<Name> tmp78;
    ca_.Bind(&block20, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78);
    CodeStubAssembler(state_).FailAssert("Torque assert 'proxy.handler == Null || Is<JSReceiver>(proxy.handler)' failed", "src/builtins/proxy-set-property.tq", 43);
  }

  if (block19.is_used()) {
    TNode<Context> tmp79;
    TNode<JSProxy> tmp80;
    TNode<Name> tmp81;
    TNode<Object> tmp82;
    TNode<Object> tmp83;
    TNode<Name> tmp84;
    ca_.Bind(&block19, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84);
  }

  if (block25.is_used()) {
    TNode<Context> tmp85;
    TNode<JSProxy> tmp86;
    TNode<Name> tmp87;
    TNode<Object> tmp88;
    TNode<Object> tmp89;
    TNode<Name> tmp90;
    TNode<HeapObject> tmp91;
    ca_.Bind(&block25, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp85}, MessageTemplate::kProxyRevoked, "set");
  }

  if (block24.is_used()) {
    TNode<Context> tmp92;
    TNode<JSProxy> tmp93;
    TNode<Name> tmp94;
    TNode<Object> tmp95;
    TNode<Object> tmp96;
    TNode<Name> tmp97;
    TNode<HeapObject> tmp98;
    TNode<JSReceiver> tmp99;
    ca_.Bind(&block24, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99);
    TNode<IntPtrT> tmp100 = ca_.IntPtrConstant(JSProxy::kTargetOffset);
    USE(tmp100);
    TNode<HeapObject>tmp101 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp93, tmp100});
    TNode<JSReceiver> tmp102;
    USE(tmp102);
    tmp102 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{tmp92}, TNode<Object>{tmp101});
    TNode<JSReceiver> tmp103;
    USE(tmp103);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp103 = GetMethod_2(state_, TNode<Context>{tmp92}, TNode<Object>{tmp99}, "set", &label0);
    ca_.Goto(&block28, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp99, tmp102, tmp99, tmp92, tmp103);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block29, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp99, tmp102, tmp99, tmp92);
    }
  }

  if (block29.is_used()) {
    TNode<Context> tmp104;
    TNode<JSProxy> tmp105;
    TNode<Name> tmp106;
    TNode<Object> tmp107;
    TNode<Object> tmp108;
    TNode<Name> tmp109;
    TNode<JSReceiver> tmp110;
    TNode<JSReceiver> tmp111;
    TNode<JSReceiver> tmp112;
    TNode<Context> tmp113;
    ca_.Bind(&block29, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113);
    CodeStubAssembler(state_).CallRuntime(Runtime::kSetPropertyWithReceiver, tmp104, tmp111, tmp106, tmp107, tmp108);
    CodeStubAssembler(state_).Return(tmp107);
  }

  if (block28.is_used()) {
    TNode<Context> tmp115;
    TNode<JSProxy> tmp116;
    TNode<Name> tmp117;
    TNode<Object> tmp118;
    TNode<Object> tmp119;
    TNode<Name> tmp120;
    TNode<JSReceiver> tmp121;
    TNode<JSReceiver> tmp122;
    TNode<JSReceiver> tmp123;
    TNode<Context> tmp124;
    TNode<JSReceiver> tmp125;
    ca_.Bind(&block28, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125);
    TNode<Object> tmp126;
    USE(tmp126);
    tmp126 = CodeStubAssembler(state_).Call(TNode<Context>{tmp115}, TNode<JSReceiver>{tmp125}, TNode<Object>{tmp121}, TNode<Object>{tmp122}, TNode<Object>{tmp120}, TNode<Object>{tmp118}, TNode<Object>{tmp119});
    TNode<BoolT> tmp127;
    USE(tmp127);
    tmp127 = ToBoolean_0(state_, TNode<Object>{tmp126});
    ca_.Branch(tmp127, &block30, &block31, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp125, tmp126);
  }

  if (block30.is_used()) {
    TNode<Context> tmp128;
    TNode<JSProxy> tmp129;
    TNode<Name> tmp130;
    TNode<Object> tmp131;
    TNode<Object> tmp132;
    TNode<Name> tmp133;
    TNode<JSReceiver> tmp134;
    TNode<JSReceiver> tmp135;
    TNode<JSReceiver> tmp136;
    TNode<Object> tmp137;
    ca_.Bind(&block30, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137);
    ProxiesCodeStubAssembler(state_).CheckGetSetTrapResult(TNode<Context>{tmp128}, TNode<JSReceiver>{tmp135}, TNode<JSProxy>{tmp129}, TNode<Name>{tmp130}, TNode<Object>{tmp131}, JSProxy::AccessKind::kSet);
    CodeStubAssembler(state_).Return(tmp131);
  }

  if (block31.is_used()) {
    TNode<Context> tmp138;
    TNode<JSProxy> tmp139;
    TNode<Name> tmp140;
    TNode<Object> tmp141;
    TNode<Object> tmp142;
    TNode<Name> tmp143;
    TNode<JSReceiver> tmp144;
    TNode<JSReceiver> tmp145;
    TNode<JSReceiver> tmp146;
    TNode<Object> tmp147;
    ca_.Bind(&block31, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147);
    TNode<Smi> tmp148;
    USE(tmp148);
    tmp148 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kProxyTrapReturnedFalsishFor);
    TNode<Object> tmp149;
    USE(tmp149);
    tmp149 = FromConstexpr_Object_constexpr_string_0(state_, "set");
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowTypeErrorIfStrict, tmp138, tmp148, tmp149, tmp140);
    CodeStubAssembler(state_).Return(tmp141);
  }
}

}  // namespace internal
}  // namespace v8

