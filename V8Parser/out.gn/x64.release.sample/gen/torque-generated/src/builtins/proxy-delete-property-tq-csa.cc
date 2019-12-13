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

TF_BUILTIN(ProxyDeleteProperty, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSProxy> parameter1 = UncheckedCast<JSProxy>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Name> parameter2 = UncheckedCast<Name>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Smi> parameter3 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi, BoolT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi, BoolT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi, BoolT, BoolT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi, HeapObject> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi, HeapObject, JSReceiver> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi, JSReceiver, JSReceiver, JSReceiver, Context> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi, JSReceiver, JSReceiver, JSReceiver, Context, JSReceiver> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi, JSReceiver, JSReceiver, JSReceiver, Object> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi, JSReceiver, JSReceiver, JSReceiver, Object> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi, JSReceiver, JSReceiver, JSReceiver, Object> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Name, Smi, JSReceiver, JSReceiver, JSReceiver, Object> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSProxy> tmp1;
    TNode<Name> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    CodeStubAssembler(state_).PerformStackCheck(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(JSProxy::kHandlerOffset);
    USE(tmp4);
    TNode<HeapObject>tmp5 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp1, tmp4});
    TNode<JSReceiver> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp5}, &label0);
    ca_.Goto(&block24, tmp0, tmp1, tmp2, tmp3, tmp5, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block25, tmp0, tmp1, tmp2, tmp3, tmp5);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<JSProxy> tmp8;
    TNode<Name> tmp9;
    TNode<Smi> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedIsNotSmi(name)' failed", "src/builtins/proxy-delete-property.tq", 18);
  }

  if (block3.is_used()) {
    TNode<Context> tmp11;
    TNode<JSProxy> tmp12;
    TNode<Name> tmp13;
    TNode<Smi> tmp14;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13, &tmp14);
  }

  if (block8.is_used()) {
    TNode<Context> tmp15;
    TNode<JSProxy> tmp16;
    TNode<Name> tmp17;
    TNode<Smi> tmp18;
    ca_.Bind(&block8, &tmp15, &tmp16, &tmp17, &tmp18);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsName(name)' failed", "src/builtins/proxy-delete-property.tq", 19);
  }

  if (block7.is_used()) {
    TNode<Context> tmp19;
    TNode<JSProxy> tmp20;
    TNode<Name> tmp21;
    TNode<Smi> tmp22;
    ca_.Bind(&block7, &tmp19, &tmp20, &tmp21, &tmp22);
  }

  if (block12.is_used()) {
    TNode<Context> tmp23;
    TNode<JSProxy> tmp24;
    TNode<Name> tmp25;
    TNode<Smi> tmp26;
    ca_.Bind(&block12, &tmp23, &tmp24, &tmp25, &tmp26);
    CodeStubAssembler(state_).FailAssert("Torque assert '!IsPrivateSymbol(name)' failed", "src/builtins/proxy-delete-property.tq", 20);
  }

  if (block11.is_used()) {
    TNode<Context> tmp27;
    TNode<JSProxy> tmp28;
    TNode<Name> tmp29;
    TNode<Smi> tmp30;
    ca_.Bind(&block11, &tmp27, &tmp28, &tmp29, &tmp30);
  }

  if (block21.is_used()) {
    TNode<Context> tmp31;
    TNode<JSProxy> tmp32;
    TNode<Name> tmp33;
    TNode<Smi> tmp34;
    TNode<BoolT> tmp35;
    ca_.Bind(&block21, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    TNode<BoolT> tmp36;
    USE(tmp36);
    tmp36 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block23, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36);
  }

  if (block22.is_used()) {
    TNode<Context> tmp37;
    TNode<JSProxy> tmp38;
    TNode<Name> tmp39;
    TNode<Smi> tmp40;
    TNode<BoolT> tmp41;
    ca_.Bind(&block22, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<IntPtrT> tmp42 = ca_.IntPtrConstant(JSProxy::kHandlerOffset);
    USE(tmp42);
    TNode<HeapObject>tmp43 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp38, tmp42});
    TNode<BoolT> tmp44;
    USE(tmp44);
    tmp44 = Is_JSReceiver_JSReceiver_OR_Null_0(state_, TNode<Context>{tmp37}, TNode<HeapObject>{tmp43});
    ca_.Goto(&block23, tmp37, tmp38, tmp39, tmp40, tmp41, tmp44);
  }

  if (block23.is_used()) {
    TNode<Context> tmp45;
    TNode<JSProxy> tmp46;
    TNode<Name> tmp47;
    TNode<Smi> tmp48;
    TNode<BoolT> tmp49;
    TNode<BoolT> tmp50;
    ca_.Bind(&block23, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50);
    ca_.Branch(tmp50, &block19, &block20, tmp45, tmp46, tmp47, tmp48);
  }

  if (block20.is_used()) {
    TNode<Context> tmp51;
    TNode<JSProxy> tmp52;
    TNode<Name> tmp53;
    TNode<Smi> tmp54;
    ca_.Bind(&block20, &tmp51, &tmp52, &tmp53, &tmp54);
    CodeStubAssembler(state_).FailAssert("Torque assert 'proxy.handler == Null || Is<JSReceiver>(proxy.handler)' failed", "src/builtins/proxy-delete-property.tq", 26);
  }

  if (block19.is_used()) {
    TNode<Context> tmp55;
    TNode<JSProxy> tmp56;
    TNode<Name> tmp57;
    TNode<Smi> tmp58;
    ca_.Bind(&block19, &tmp55, &tmp56, &tmp57, &tmp58);
  }

  if (block25.is_used()) {
    TNode<Context> tmp59;
    TNode<JSProxy> tmp60;
    TNode<Name> tmp61;
    TNode<Smi> tmp62;
    TNode<HeapObject> tmp63;
    ca_.Bind(&block25, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp59}, MessageTemplate::kProxyRevoked, "deleteProperty");
  }

  if (block24.is_used()) {
    TNode<Context> tmp64;
    TNode<JSProxy> tmp65;
    TNode<Name> tmp66;
    TNode<Smi> tmp67;
    TNode<HeapObject> tmp68;
    TNode<JSReceiver> tmp69;
    ca_.Bind(&block24, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69);
    TNode<IntPtrT> tmp70 = ca_.IntPtrConstant(JSProxy::kTargetOffset);
    USE(tmp70);
    TNode<HeapObject>tmp71 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp65, tmp70});
    TNode<JSReceiver> tmp72;
    USE(tmp72);
    tmp72 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{tmp64}, TNode<Object>{tmp71});
    TNode<JSReceiver> tmp73;
    USE(tmp73);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp73 = GetMethod_2(state_, TNode<Context>{tmp64}, TNode<Object>{tmp69}, "deleteProperty", &label0);
    ca_.Goto(&block28, tmp64, tmp65, tmp66, tmp67, tmp69, tmp72, tmp69, tmp64, tmp73);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block29, tmp64, tmp65, tmp66, tmp67, tmp69, tmp72, tmp69, tmp64);
    }
  }

  if (block29.is_used()) {
    TNode<Context> tmp74;
    TNode<JSProxy> tmp75;
    TNode<Name> tmp76;
    TNode<Smi> tmp77;
    TNode<JSReceiver> tmp78;
    TNode<JSReceiver> tmp79;
    TNode<JSReceiver> tmp80;
    TNode<Context> tmp81;
    ca_.Bind(&block29, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
    TNode<Oddball> tmp82;
    tmp82 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kDeleteProperty, tmp74, tmp79, tmp76, tmp77));
    USE(tmp82);
    CodeStubAssembler(state_).Return(tmp82);
  }

  if (block28.is_used()) {
    TNode<Context> tmp83;
    TNode<JSProxy> tmp84;
    TNode<Name> tmp85;
    TNode<Smi> tmp86;
    TNode<JSReceiver> tmp87;
    TNode<JSReceiver> tmp88;
    TNode<JSReceiver> tmp89;
    TNode<Context> tmp90;
    TNode<JSReceiver> tmp91;
    ca_.Bind(&block28, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91);
    TNode<Object> tmp92;
    USE(tmp92);
    tmp92 = CodeStubAssembler(state_).Call(TNode<Context>{tmp83}, TNode<JSReceiver>{tmp91}, TNode<Object>{tmp87}, TNode<Object>{tmp88}, TNode<Object>{tmp85});
    TNode<BoolT> tmp93;
    USE(tmp93);
    tmp93 = ToBoolean_0(state_, TNode<Object>{tmp92});
    TNode<BoolT> tmp94;
    USE(tmp94);
    tmp94 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp93});
    ca_.Branch(tmp94, &block30, &block31, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp91, tmp92);
  }

  if (block30.is_used()) {
    TNode<Context> tmp95;
    TNode<JSProxy> tmp96;
    TNode<Name> tmp97;
    TNode<Smi> tmp98;
    TNode<JSReceiver> tmp99;
    TNode<JSReceiver> tmp100;
    TNode<JSReceiver> tmp101;
    TNode<Object> tmp102;
    ca_.Bind(&block30, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102);
    TNode<Smi> tmp103;
    USE(tmp103);
    tmp103 = CodeStubAssembler(state_).SmiConstant(LanguageMode::kStrict);
    TNode<BoolT> tmp104;
    USE(tmp104);
    tmp104 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp98}, TNode<Smi>{tmp103});
    ca_.Branch(tmp104, &block32, &block33, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102);
  }

  if (block32.is_used()) {
    TNode<Context> tmp105;
    TNode<JSProxy> tmp106;
    TNode<Name> tmp107;
    TNode<Smi> tmp108;
    TNode<JSReceiver> tmp109;
    TNode<JSReceiver> tmp110;
    TNode<JSReceiver> tmp111;
    TNode<Object> tmp112;
    ca_.Bind(&block32, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112);
    TNode<Object> tmp113;
    USE(tmp113);
    tmp113 = FromConstexpr_Object_constexpr_string_0(state_, "deleteProperty");
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp105}, MessageTemplate::kProxyTrapReturnedFalsishFor, TNode<Object>{tmp113}, TNode<Object>{tmp107});
  }

  if (block33.is_used()) {
    TNode<Context> tmp114;
    TNode<JSProxy> tmp115;
    TNode<Name> tmp116;
    TNode<Smi> tmp117;
    TNode<JSReceiver> tmp118;
    TNode<JSReceiver> tmp119;
    TNode<JSReceiver> tmp120;
    TNode<Object> tmp121;
    ca_.Bind(&block33, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121);
    TNode<Oddball> tmp122;
    USE(tmp122);
    tmp122 = False_0(state_);
    CodeStubAssembler(state_).Return(tmp122);
  }

  if (block31.is_used()) {
    TNode<Context> tmp123;
    TNode<JSProxy> tmp124;
    TNode<Name> tmp125;
    TNode<Smi> tmp126;
    TNode<JSReceiver> tmp127;
    TNode<JSReceiver> tmp128;
    TNode<JSReceiver> tmp129;
    TNode<Object> tmp130;
    ca_.Bind(&block31, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130);
    ProxiesCodeStubAssembler(state_).CheckDeleteTrapResult(TNode<Context>{tmp123}, TNode<JSReceiver>{tmp128}, TNode<JSProxy>{tmp124}, TNode<Name>{tmp125});
    TNode<Oddball> tmp131;
    USE(tmp131);
    tmp131 = True_0(state_);
    CodeStubAssembler(state_).Return(tmp131);
  }
}

TNode<BoolT> Is_JSReceiver_JSReceiver_OR_Null_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSReceiver> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<HeapObject> tmp8;
    TNode<HeapObject> tmp9;
    TNode<JSReceiver> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<HeapObject> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<HeapObject> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

}  // namespace internal
}  // namespace v8

