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

TF_BUILTIN(ProxySetPrototypeOf, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSProxy> parameter1 = UncheckedCast<JSProxy>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<HeapObject> parameter2 = UncheckedCast<HeapObject>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Oddball> parameter3 = UncheckedCast<Oddball>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, BoolT, BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, BoolT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, BoolT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, BoolT, BoolT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, HeapObject> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, HeapObject, JSReceiver> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Context> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Context, JSReceiver> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Object> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Object> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Object> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Object> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object, BoolT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object, BoolT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object, BoolT, BoolT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object, Object> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, JSReceiver, HeapObject, JSReceiver, Object, Object, Object> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, Object, HeapObject> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSProxy, HeapObject, Oddball, Object, HeapObject> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSProxy> tmp1;
    TNode<HeapObject> tmp2;
    TNode<Oddball> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    CodeStubAssembler(state_).PerformStackCheck(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(JSProxy::kHandlerOffset);
    USE(tmp4);
    TNode<HeapObject>tmp5 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp1, tmp4});
    TNode<JSReceiver> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp5}, &label0);
    ca_.Goto(&block19, tmp0, tmp1, tmp2, tmp3, tmp5, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block20, tmp0, tmp1, tmp2, tmp3, tmp5);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp7;
    TNode<JSProxy> tmp8;
    TNode<HeapObject> tmp9;
    TNode<Oddball> tmp10;
    TNode<BoolT> tmp11;
    ca_.Bind(&block9, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block11, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12);
  }

  if (block10.is_used()) {
    TNode<Context> tmp13;
    TNode<JSProxy> tmp14;
    TNode<HeapObject> tmp15;
    TNode<Oddball> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block10, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = Is_JSReceiver_JSReceiver_OR_Null_0(state_, TNode<Context>{tmp13}, TNode<HeapObject>{tmp15});
    ca_.Goto(&block11, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18);
  }

  if (block11.is_used()) {
    TNode<Context> tmp19;
    TNode<JSProxy> tmp20;
    TNode<HeapObject> tmp21;
    TNode<Oddball> tmp22;
    TNode<BoolT> tmp23;
    TNode<BoolT> tmp24;
    ca_.Bind(&block11, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    ca_.Branch(tmp24, &block7, &block8, tmp19, tmp20, tmp21, tmp22);
  }

  if (block8.is_used()) {
    TNode<Context> tmp25;
    TNode<JSProxy> tmp26;
    TNode<HeapObject> tmp27;
    TNode<Oddball> tmp28;
    ca_.Bind(&block8, &tmp25, &tmp26, &tmp27, &tmp28);
    CodeStubAssembler(state_).FailAssert("Torque assert 'proto == Null || Is<JSReceiver>(proto)' failed", "src/builtins/proxy-set-prototype-of.tq", 18);
  }

  if (block7.is_used()) {
    TNode<Context> tmp29;
    TNode<JSProxy> tmp30;
    TNode<HeapObject> tmp31;
    TNode<Oddball> tmp32;
    ca_.Bind(&block7, &tmp29, &tmp30, &tmp31, &tmp32);
  }

  if (block16.is_used()) {
    TNode<Context> tmp33;
    TNode<JSProxy> tmp34;
    TNode<HeapObject> tmp35;
    TNode<Oddball> tmp36;
    TNode<BoolT> tmp37;
    ca_.Bind(&block16, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    TNode<BoolT> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block18, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38);
  }

  if (block17.is_used()) {
    TNode<Context> tmp39;
    TNode<JSProxy> tmp40;
    TNode<HeapObject> tmp41;
    TNode<Oddball> tmp42;
    TNode<BoolT> tmp43;
    ca_.Bind(&block17, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<IntPtrT> tmp44 = ca_.IntPtrConstant(JSProxy::kHandlerOffset);
    USE(tmp44);
    TNode<HeapObject>tmp45 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp40, tmp44});
    TNode<BoolT> tmp46;
    USE(tmp46);
    tmp46 = Is_JSReceiver_JSReceiver_OR_Null_0(state_, TNode<Context>{tmp39}, TNode<HeapObject>{tmp45});
    ca_.Goto(&block18, tmp39, tmp40, tmp41, tmp42, tmp43, tmp46);
  }

  if (block18.is_used()) {
    TNode<Context> tmp47;
    TNode<JSProxy> tmp48;
    TNode<HeapObject> tmp49;
    TNode<Oddball> tmp50;
    TNode<BoolT> tmp51;
    TNode<BoolT> tmp52;
    ca_.Bind(&block18, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52);
    ca_.Branch(tmp52, &block14, &block15, tmp47, tmp48, tmp49, tmp50);
  }

  if (block15.is_used()) {
    TNode<Context> tmp53;
    TNode<JSProxy> tmp54;
    TNode<HeapObject> tmp55;
    TNode<Oddball> tmp56;
    ca_.Bind(&block15, &tmp53, &tmp54, &tmp55, &tmp56);
    CodeStubAssembler(state_).FailAssert("Torque assert 'proxy.handler == Null || Is<JSReceiver>(proxy.handler)' failed", "src/builtins/proxy-set-prototype-of.tq", 23);
  }

  if (block14.is_used()) {
    TNode<Context> tmp57;
    TNode<JSProxy> tmp58;
    TNode<HeapObject> tmp59;
    TNode<Oddball> tmp60;
    ca_.Bind(&block14, &tmp57, &tmp58, &tmp59, &tmp60);
  }

  if (block20.is_used()) {
    TNode<Context> tmp61;
    TNode<JSProxy> tmp62;
    TNode<HeapObject> tmp63;
    TNode<Oddball> tmp64;
    TNode<HeapObject> tmp65;
    ca_.Bind(&block20, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp61}, MessageTemplate::kProxyRevoked, "setPrototypeOf");
  }

  if (block19.is_used()) {
    TNode<Context> tmp66;
    TNode<JSProxy> tmp67;
    TNode<HeapObject> tmp68;
    TNode<Oddball> tmp69;
    TNode<HeapObject> tmp70;
    TNode<JSReceiver> tmp71;
    ca_.Bind(&block19, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71);
    TNode<IntPtrT> tmp72 = ca_.IntPtrConstant(JSProxy::kTargetOffset);
    USE(tmp72);
    TNode<HeapObject>tmp73 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp67, tmp72});
    TNode<JSReceiver> tmp74;
    USE(tmp74);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp74 = GetMethod_2(state_, TNode<Context>{tmp66}, TNode<Object>{tmp71}, "setPrototypeOf", &label0);
    ca_.Goto(&block23, tmp66, tmp67, tmp68, tmp69, tmp71, tmp73, tmp71, tmp66, tmp74);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block24, tmp66, tmp67, tmp68, tmp69, tmp71, tmp73, tmp71, tmp66);
    }
  }

  if (block24.is_used()) {
    TNode<Context> tmp75;
    TNode<JSProxy> tmp76;
    TNode<HeapObject> tmp77;
    TNode<Oddball> tmp78;
    TNode<JSReceiver> tmp79;
    TNode<HeapObject> tmp80;
    TNode<JSReceiver> tmp81;
    TNode<Context> tmp82;
    ca_.Bind(&block24, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82);
    TNode<Oddball> tmp83;
    USE(tmp83);
    tmp83 = True_0(state_);
    TNode<BoolT> tmp84;
    USE(tmp84);
    tmp84 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp78}, TNode<HeapObject>{tmp83});
    ca_.Branch(tmp84, &block40, &block41, tmp75, tmp76, tmp77, tmp78, tmp80, tmp77);
  }

  if (block23.is_used()) {
    TNode<Context> tmp85;
    TNode<JSProxy> tmp86;
    TNode<HeapObject> tmp87;
    TNode<Oddball> tmp88;
    TNode<JSReceiver> tmp89;
    TNode<HeapObject> tmp90;
    TNode<JSReceiver> tmp91;
    TNode<Context> tmp92;
    TNode<JSReceiver> tmp93;
    ca_.Bind(&block23, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93);
    TNode<Object> tmp94;
    USE(tmp94);
    tmp94 = CodeStubAssembler(state_).Call(TNode<Context>{tmp85}, TNode<JSReceiver>{tmp93}, TNode<Object>{tmp89}, TNode<Object>{tmp90}, TNode<Object>{tmp87});
    TNode<BoolT> tmp95;
    USE(tmp95);
    tmp95 = ToBoolean_0(state_, TNode<Object>{tmp94});
    TNode<BoolT> tmp96;
    USE(tmp96);
    tmp96 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp95});
    ca_.Branch(tmp96, &block25, &block26, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp93, tmp94);
  }

  if (block25.is_used()) {
    TNode<Context> tmp97;
    TNode<JSProxy> tmp98;
    TNode<HeapObject> tmp99;
    TNode<Oddball> tmp100;
    TNode<JSReceiver> tmp101;
    TNode<HeapObject> tmp102;
    TNode<JSReceiver> tmp103;
    TNode<Object> tmp104;
    ca_.Bind(&block25, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104);
    TNode<Oddball> tmp105;
    USE(tmp105);
    tmp105 = True_0(state_);
    TNode<BoolT> tmp106;
    USE(tmp106);
    tmp106 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp100}, TNode<HeapObject>{tmp105});
    ca_.Branch(tmp106, &block27, &block28, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104);
  }

  if (block27.is_used()) {
    TNode<Context> tmp107;
    TNode<JSProxy> tmp108;
    TNode<HeapObject> tmp109;
    TNode<Oddball> tmp110;
    TNode<JSReceiver> tmp111;
    TNode<HeapObject> tmp112;
    TNode<JSReceiver> tmp113;
    TNode<Object> tmp114;
    ca_.Bind(&block27, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp107}, MessageTemplate::kProxyTrapReturnedFalsishFor, "setPrototypeOf");
  }

  if (block28.is_used()) {
    TNode<Context> tmp115;
    TNode<JSProxy> tmp116;
    TNode<HeapObject> tmp117;
    TNode<Oddball> tmp118;
    TNode<JSReceiver> tmp119;
    TNode<HeapObject> tmp120;
    TNode<JSReceiver> tmp121;
    TNode<Object> tmp122;
    ca_.Bind(&block28, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122);
    TNode<Oddball> tmp123;
    USE(tmp123);
    tmp123 = False_0(state_);
    CodeStubAssembler(state_).Return(tmp123);
  }

  if (block26.is_used()) {
    TNode<Context> tmp124;
    TNode<JSProxy> tmp125;
    TNode<HeapObject> tmp126;
    TNode<Oddball> tmp127;
    TNode<JSReceiver> tmp128;
    TNode<HeapObject> tmp129;
    TNode<JSReceiver> tmp130;
    TNode<Object> tmp131;
    ca_.Bind(&block26, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131);
    TNode<Object> tmp132;
    USE(tmp132);
    tmp132 = ObjectIsExtensibleImpl_0(state_, TNode<Context>{tmp124}, TNode<Object>{tmp129});
    TNode<Oddball> tmp133;
    USE(tmp133);
    tmp133 = True_0(state_);
    TNode<BoolT> tmp134;
    USE(tmp134);
    tmp134 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp132}, TNode<HeapObject>{tmp133});
    ca_.Branch(tmp134, &block36, &block37, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132);
  }

  if (block33.is_used()) {
    TNode<Context> tmp135;
    TNode<JSProxy> tmp136;
    TNode<HeapObject> tmp137;
    TNode<Oddball> tmp138;
    TNode<JSReceiver> tmp139;
    TNode<HeapObject> tmp140;
    TNode<JSReceiver> tmp141;
    TNode<Object> tmp142;
    TNode<Object> tmp143;
    TNode<BoolT> tmp144;
    ca_.Bind(&block33, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144);
    TNode<BoolT> tmp145;
    USE(tmp145);
    tmp145 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block35, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145);
  }

  if (block34.is_used()) {
    TNode<Context> tmp146;
    TNode<JSProxy> tmp147;
    TNode<HeapObject> tmp148;
    TNode<Oddball> tmp149;
    TNode<JSReceiver> tmp150;
    TNode<HeapObject> tmp151;
    TNode<JSReceiver> tmp152;
    TNode<Object> tmp153;
    TNode<Object> tmp154;
    TNode<BoolT> tmp155;
    ca_.Bind(&block34, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155);
    TNode<Oddball> tmp156;
    USE(tmp156);
    tmp156 = False_0(state_);
    TNode<BoolT> tmp157;
    USE(tmp157);
    tmp157 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp154}, TNode<HeapObject>{tmp156});
    ca_.Goto(&block35, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp157);
  }

  if (block35.is_used()) {
    TNode<Context> tmp158;
    TNode<JSProxy> tmp159;
    TNode<HeapObject> tmp160;
    TNode<Oddball> tmp161;
    TNode<JSReceiver> tmp162;
    TNode<HeapObject> tmp163;
    TNode<JSReceiver> tmp164;
    TNode<Object> tmp165;
    TNode<Object> tmp166;
    TNode<BoolT> tmp167;
    TNode<BoolT> tmp168;
    ca_.Bind(&block35, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168);
    ca_.Branch(tmp168, &block31, &block32, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, tmp164, tmp165, tmp166);
  }

  if (block32.is_used()) {
    TNode<Context> tmp169;
    TNode<JSProxy> tmp170;
    TNode<HeapObject> tmp171;
    TNode<Oddball> tmp172;
    TNode<JSReceiver> tmp173;
    TNode<HeapObject> tmp174;
    TNode<JSReceiver> tmp175;
    TNode<Object> tmp176;
    TNode<Object> tmp177;
    ca_.Bind(&block32, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177);
    CodeStubAssembler(state_).FailAssert("Torque assert 'extensibleTarget == True || extensibleTarget == False' failed", "src/builtins/proxy-set-prototype-of.tq", 50);
  }

  if (block31.is_used()) {
    TNode<Context> tmp178;
    TNode<JSProxy> tmp179;
    TNode<HeapObject> tmp180;
    TNode<Oddball> tmp181;
    TNode<JSReceiver> tmp182;
    TNode<HeapObject> tmp183;
    TNode<JSReceiver> tmp184;
    TNode<Object> tmp185;
    TNode<Object> tmp186;
    ca_.Bind(&block31, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186);
  }

  if (block36.is_used()) {
    TNode<Context> tmp187;
    TNode<JSProxy> tmp188;
    TNode<HeapObject> tmp189;
    TNode<Oddball> tmp190;
    TNode<JSReceiver> tmp191;
    TNode<HeapObject> tmp192;
    TNode<JSReceiver> tmp193;
    TNode<Object> tmp194;
    TNode<Object> tmp195;
    ca_.Bind(&block36, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195);
    TNode<Oddball> tmp196;
    USE(tmp196);
    tmp196 = True_0(state_);
    CodeStubAssembler(state_).Return(tmp196);
  }

  if (block37.is_used()) {
    TNode<Context> tmp197;
    TNode<JSProxy> tmp198;
    TNode<HeapObject> tmp199;
    TNode<Oddball> tmp200;
    TNode<JSReceiver> tmp201;
    TNode<HeapObject> tmp202;
    TNode<JSReceiver> tmp203;
    TNode<Object> tmp204;
    TNode<Object> tmp205;
    ca_.Bind(&block37, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205);
    TNode<Object> tmp206;
    USE(tmp206);
    tmp206 = ObjectGetPrototypeOfImpl_0(state_, TNode<Context>{tmp197}, TNode<Object>{tmp202});
    TNode<BoolT> tmp207;
    USE(tmp207);
    tmp207 = SameValue_0(state_, TNode<Object>{tmp199}, TNode<Object>{tmp206});
    ca_.Branch(tmp207, &block38, &block39, tmp197, tmp198, tmp199, tmp200, tmp201, tmp202, tmp203, tmp204, tmp205, tmp206);
  }

  if (block38.is_used()) {
    TNode<Context> tmp208;
    TNode<JSProxy> tmp209;
    TNode<HeapObject> tmp210;
    TNode<Oddball> tmp211;
    TNode<JSReceiver> tmp212;
    TNode<HeapObject> tmp213;
    TNode<JSReceiver> tmp214;
    TNode<Object> tmp215;
    TNode<Object> tmp216;
    TNode<Object> tmp217;
    ca_.Bind(&block38, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217);
    TNode<Oddball> tmp218;
    USE(tmp218);
    tmp218 = True_0(state_);
    CodeStubAssembler(state_).Return(tmp218);
  }

  if (block39.is_used()) {
    TNode<Context> tmp219;
    TNode<JSProxy> tmp220;
    TNode<HeapObject> tmp221;
    TNode<Oddball> tmp222;
    TNode<JSReceiver> tmp223;
    TNode<HeapObject> tmp224;
    TNode<JSReceiver> tmp225;
    TNode<Object> tmp226;
    TNode<Object> tmp227;
    TNode<Object> tmp228;
    ca_.Bind(&block39, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp219}, MessageTemplate::kProxySetPrototypeOfNonExtensible);
  }

  if (block40.is_used()) {
    TNode<Context> tmp229;
    TNode<JSProxy> tmp230;
    TNode<HeapObject> tmp231;
    TNode<Oddball> tmp232;
    TNode<Object> tmp233;
    TNode<HeapObject> tmp234;
    ca_.Bind(&block40, &tmp229, &tmp230, &tmp231, &tmp232, &tmp233, &tmp234);
    TNode<Object> tmp235;
    USE(tmp235);
    tmp235 = ObjectSetPrototypeOfThrow_0(state_, TNode<Context>{tmp229}, TNode<Object>{tmp233}, TNode<HeapObject>{tmp234});
    CodeStubAssembler(state_).Return(tmp235);
  }

  if (block41.is_used()) {
    TNode<Context> tmp236;
    TNode<JSProxy> tmp237;
    TNode<HeapObject> tmp238;
    TNode<Oddball> tmp239;
    TNode<Object> tmp240;
    TNode<HeapObject> tmp241;
    ca_.Bind(&block41, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241);
    TNode<Object> tmp242;
    USE(tmp242);
    tmp242 = ObjectSetPrototypeOfDontThrow_0(state_, TNode<Context>{tmp236}, TNode<Object>{tmp240}, TNode<HeapObject>{tmp241});
    CodeStubAssembler(state_).Return(tmp242);
  }
}

}  // namespace internal
}  // namespace v8

