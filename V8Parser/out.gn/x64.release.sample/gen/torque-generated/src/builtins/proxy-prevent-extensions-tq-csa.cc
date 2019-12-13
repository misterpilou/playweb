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

TF_BUILTIN(ProxyPreventExtensions, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSProxy> parameter1 = UncheckedCast<JSProxy>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Oddball> parameter2 = UncheckedCast<Oddball>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, BoolT, BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, HeapObject> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, HeapObject, JSReceiver> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, JSReceiver, HeapObject, JSReceiver, Context> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, JSReceiver, HeapObject, JSReceiver, Context, JSReceiver> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, JSReceiver, HeapObject, JSReceiver, Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object, BoolT> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object, BoolT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object, BoolT, BoolT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object> block24(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, JSReceiver, HeapObject, JSReceiver, Object> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, JSReceiver, HeapObject, JSReceiver, Object> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, JSReceiver, HeapObject, JSReceiver, Object> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, Object> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, Oddball, Object> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSProxy> tmp1;
    TNode<Oddball> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    CodeStubAssembler(state_).PerformStackCheck(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp3 = ca_.IntPtrConstant(JSProxy::kHandlerOffset);
    USE(tmp3);
    TNode<HeapObject>tmp4 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp1, tmp3});
    TNode<JSReceiver> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp4}, &label0);
    ca_.Goto(&block12, tmp0, tmp1, tmp2, tmp4, tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block13, tmp0, tmp1, tmp2, tmp4);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp6;
    TNode<JSProxy> tmp7;
    TNode<Oddball> tmp8;
    TNode<BoolT> tmp9;
    ca_.Bind(&block9, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block11, tmp6, tmp7, tmp8, tmp9, tmp10);
  }

  if (block10.is_used()) {
    TNode<Context> tmp11;
    TNode<JSProxy> tmp12;
    TNode<Oddball> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<IntPtrT> tmp15 = ca_.IntPtrConstant(JSProxy::kHandlerOffset);
    USE(tmp15);
    TNode<HeapObject>tmp16 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp12, tmp15});
    TNode<BoolT> tmp17;
    USE(tmp17);
    tmp17 = Is_JSReceiver_JSReceiver_OR_Null_0(state_, TNode<Context>{tmp11}, TNode<HeapObject>{tmp16});
    ca_.Goto(&block11, tmp11, tmp12, tmp13, tmp14, tmp17);
  }

  if (block11.is_used()) {
    TNode<Context> tmp18;
    TNode<JSProxy> tmp19;
    TNode<Oddball> tmp20;
    TNode<BoolT> tmp21;
    TNode<BoolT> tmp22;
    ca_.Bind(&block11, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    ca_.Branch(tmp22, &block7, &block8, tmp18, tmp19, tmp20);
  }

  if (block8.is_used()) {
    TNode<Context> tmp23;
    TNode<JSProxy> tmp24;
    TNode<Oddball> tmp25;
    ca_.Bind(&block8, &tmp23, &tmp24, &tmp25);
    CodeStubAssembler(state_).FailAssert("Torque assert 'proxy.handler == Null || Is<JSReceiver>(proxy.handler)' failed", "src/builtins/proxy-prevent-extensions.tq", 20);
  }

  if (block7.is_used()) {
    TNode<Context> tmp26;
    TNode<JSProxy> tmp27;
    TNode<Oddball> tmp28;
    ca_.Bind(&block7, &tmp26, &tmp27, &tmp28);
  }

  if (block13.is_used()) {
    TNode<Context> tmp29;
    TNode<JSProxy> tmp30;
    TNode<Oddball> tmp31;
    TNode<HeapObject> tmp32;
    ca_.Bind(&block13, &tmp29, &tmp30, &tmp31, &tmp32);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp29}, MessageTemplate::kProxyRevoked, "preventExtensions");
  }

  if (block12.is_used()) {
    TNode<Context> tmp33;
    TNode<JSProxy> tmp34;
    TNode<Oddball> tmp35;
    TNode<HeapObject> tmp36;
    TNode<JSReceiver> tmp37;
    ca_.Bind(&block12, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    TNode<IntPtrT> tmp38 = ca_.IntPtrConstant(JSProxy::kTargetOffset);
    USE(tmp38);
    TNode<HeapObject>tmp39 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp34, tmp38});
    TNode<JSReceiver> tmp40;
    USE(tmp40);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp40 = GetMethod_2(state_, TNode<Context>{tmp33}, TNode<Object>{tmp37}, "preventExtensions", &label0);
    ca_.Goto(&block16, tmp33, tmp34, tmp35, tmp37, tmp39, tmp37, tmp33, tmp40);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block17, tmp33, tmp34, tmp35, tmp37, tmp39, tmp37, tmp33);
    }
  }

  if (block17.is_used()) {
    TNode<Context> tmp41;
    TNode<JSProxy> tmp42;
    TNode<Oddball> tmp43;
    TNode<JSReceiver> tmp44;
    TNode<HeapObject> tmp45;
    TNode<JSReceiver> tmp46;
    TNode<Context> tmp47;
    ca_.Bind(&block17, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    TNode<Oddball> tmp48;
    USE(tmp48);
    tmp48 = True_0(state_);
    TNode<BoolT> tmp49;
    USE(tmp49);
    tmp49 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp43}, TNode<HeapObject>{tmp48});
    ca_.Branch(tmp49, &block32, &block33, tmp41, tmp42, tmp43, tmp45);
  }

  if (block16.is_used()) {
    TNode<Context> tmp50;
    TNode<JSProxy> tmp51;
    TNode<Oddball> tmp52;
    TNode<JSReceiver> tmp53;
    TNode<HeapObject> tmp54;
    TNode<JSReceiver> tmp55;
    TNode<Context> tmp56;
    TNode<JSReceiver> tmp57;
    ca_.Bind(&block16, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57);
    TNode<Object> tmp58;
    USE(tmp58);
    tmp58 = CodeStubAssembler(state_).Call(TNode<Context>{tmp50}, TNode<JSReceiver>{tmp57}, TNode<Object>{tmp53}, TNode<Object>{tmp54});
    TNode<BoolT> tmp59;
    USE(tmp59);
    tmp59 = ToBoolean_0(state_, TNode<Object>{tmp58});
    ca_.Branch(tmp59, &block18, &block19, tmp50, tmp51, tmp52, tmp53, tmp54, tmp57, tmp58);
  }

  if (block18.is_used()) {
    TNode<Context> tmp60;
    TNode<JSProxy> tmp61;
    TNode<Oddball> tmp62;
    TNode<JSReceiver> tmp63;
    TNode<HeapObject> tmp64;
    TNode<JSReceiver> tmp65;
    TNode<Object> tmp66;
    ca_.Bind(&block18, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66);
    TNode<Object> tmp67;
    USE(tmp67);
    tmp67 = ObjectIsExtensibleImpl_0(state_, TNode<Context>{tmp60}, TNode<Object>{tmp64});
    TNode<Oddball> tmp68;
    USE(tmp68);
    tmp68 = True_0(state_);
    TNode<BoolT> tmp69;
    USE(tmp69);
    tmp69 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp67}, TNode<HeapObject>{tmp68});
    ca_.Branch(tmp69, &block28, &block29, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67);
  }

  if (block25.is_used()) {
    TNode<Context> tmp70;
    TNode<JSProxy> tmp71;
    TNode<Oddball> tmp72;
    TNode<JSReceiver> tmp73;
    TNode<HeapObject> tmp74;
    TNode<JSReceiver> tmp75;
    TNode<Object> tmp76;
    TNode<Object> tmp77;
    TNode<BoolT> tmp78;
    ca_.Bind(&block25, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78);
    TNode<BoolT> tmp79;
    USE(tmp79);
    tmp79 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block27, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79);
  }

  if (block26.is_used()) {
    TNode<Context> tmp80;
    TNode<JSProxy> tmp81;
    TNode<Oddball> tmp82;
    TNode<JSReceiver> tmp83;
    TNode<HeapObject> tmp84;
    TNode<JSReceiver> tmp85;
    TNode<Object> tmp86;
    TNode<Object> tmp87;
    TNode<BoolT> tmp88;
    ca_.Bind(&block26, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88);
    TNode<Oddball> tmp89;
    USE(tmp89);
    tmp89 = False_0(state_);
    TNode<BoolT> tmp90;
    USE(tmp90);
    tmp90 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp87}, TNode<HeapObject>{tmp89});
    ca_.Goto(&block27, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp90);
  }

  if (block27.is_used()) {
    TNode<Context> tmp91;
    TNode<JSProxy> tmp92;
    TNode<Oddball> tmp93;
    TNode<JSReceiver> tmp94;
    TNode<HeapObject> tmp95;
    TNode<JSReceiver> tmp96;
    TNode<Object> tmp97;
    TNode<Object> tmp98;
    TNode<BoolT> tmp99;
    TNode<BoolT> tmp100;
    ca_.Bind(&block27, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100);
    ca_.Branch(tmp100, &block23, &block24, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98);
  }

  if (block24.is_used()) {
    TNode<Context> tmp101;
    TNode<JSProxy> tmp102;
    TNode<Oddball> tmp103;
    TNode<JSReceiver> tmp104;
    TNode<HeapObject> tmp105;
    TNode<JSReceiver> tmp106;
    TNode<Object> tmp107;
    TNode<Object> tmp108;
    ca_.Bind(&block24, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108);
    CodeStubAssembler(state_).FailAssert("Torque assert 'extensibleTarget == True || extensibleTarget == False' failed", "src/builtins/proxy-prevent-extensions.tq", 41);
  }

  if (block23.is_used()) {
    TNode<Context> tmp109;
    TNode<JSProxy> tmp110;
    TNode<Oddball> tmp111;
    TNode<JSReceiver> tmp112;
    TNode<HeapObject> tmp113;
    TNode<JSReceiver> tmp114;
    TNode<Object> tmp115;
    TNode<Object> tmp116;
    ca_.Bind(&block23, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116);
  }

  if (block28.is_used()) {
    TNode<Context> tmp117;
    TNode<JSProxy> tmp118;
    TNode<Oddball> tmp119;
    TNode<JSReceiver> tmp120;
    TNode<HeapObject> tmp121;
    TNode<JSReceiver> tmp122;
    TNode<Object> tmp123;
    TNode<Object> tmp124;
    ca_.Bind(&block28, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp117}, MessageTemplate::kProxyPreventExtensionsExtensible);
  }

  if (block29.is_used()) {
    TNode<Context> tmp125;
    TNode<JSProxy> tmp126;
    TNode<Oddball> tmp127;
    TNode<JSReceiver> tmp128;
    TNode<HeapObject> tmp129;
    TNode<JSReceiver> tmp130;
    TNode<Object> tmp131;
    TNode<Object> tmp132;
    ca_.Bind(&block29, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132);
    TNode<Oddball> tmp133;
    USE(tmp133);
    tmp133 = True_0(state_);
    CodeStubAssembler(state_).Return(tmp133);
  }

  if (block19.is_used()) {
    TNode<Context> tmp134;
    TNode<JSProxy> tmp135;
    TNode<Oddball> tmp136;
    TNode<JSReceiver> tmp137;
    TNode<HeapObject> tmp138;
    TNode<JSReceiver> tmp139;
    TNode<Object> tmp140;
    ca_.Bind(&block19, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140);
    TNode<Oddball> tmp141;
    USE(tmp141);
    tmp141 = True_0(state_);
    TNode<BoolT> tmp142;
    USE(tmp142);
    tmp142 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp136}, TNode<HeapObject>{tmp141});
    ca_.Branch(tmp142, &block30, &block31, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140);
  }

  if (block30.is_used()) {
    TNode<Context> tmp143;
    TNode<JSProxy> tmp144;
    TNode<Oddball> tmp145;
    TNode<JSReceiver> tmp146;
    TNode<HeapObject> tmp147;
    TNode<JSReceiver> tmp148;
    TNode<Object> tmp149;
    ca_.Bind(&block30, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp143}, MessageTemplate::kProxyTrapReturnedFalsish, "preventExtensions");
  }

  if (block31.is_used()) {
    TNode<Context> tmp150;
    TNode<JSProxy> tmp151;
    TNode<Oddball> tmp152;
    TNode<JSReceiver> tmp153;
    TNode<HeapObject> tmp154;
    TNode<JSReceiver> tmp155;
    TNode<Object> tmp156;
    ca_.Bind(&block31, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156);
    TNode<Oddball> tmp157;
    USE(tmp157);
    tmp157 = False_0(state_);
    CodeStubAssembler(state_).Return(tmp157);
  }

  if (block32.is_used()) {
    TNode<Context> tmp158;
    TNode<JSProxy> tmp159;
    TNode<Oddball> tmp160;
    TNode<Object> tmp161;
    ca_.Bind(&block32, &tmp158, &tmp159, &tmp160, &tmp161);
    TNode<Object> tmp162;
    USE(tmp162);
    tmp162 = ObjectPreventExtensionsThrow_0(state_, TNode<Context>{tmp158}, TNode<Object>{tmp161});
    CodeStubAssembler(state_).Return(tmp162);
  }

  if (block33.is_used()) {
    TNode<Context> tmp163;
    TNode<JSProxy> tmp164;
    TNode<Oddball> tmp165;
    TNode<Object> tmp166;
    ca_.Bind(&block33, &tmp163, &tmp164, &tmp165, &tmp166);
    TNode<Object> tmp167;
    USE(tmp167);
    tmp167 = ObjectPreventExtensionsDontThrow_0(state_, TNode<Context>{tmp163}, TNode<Object>{tmp166});
    CodeStubAssembler(state_).Return(tmp167);
  }
}

}  // namespace internal
}  // namespace v8

