// Code generated by protoc-gen-go. DO NOT EDIT.
// source: request.proto

package colly_protofiles

import (
	fmt "fmt"
	proto "github.com/golang/protobuf/proto"
	any "github.com/golang/protobuf/ptypes/any"
	math "math"
)

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.ProtoPackageIsVersion3 // please upgrade the proto package

type Context struct {
	Ctx                  map[string]string `protobuf:"bytes,1,rep,name=Ctx,proto3" json:"Ctx,omitempty" protobuf_key:"bytes,1,opt,name=key,proto3" protobuf_val:"bytes,2,opt,name=value,proto3"`
	XXX_NoUnkeyedLiteral struct{}          `json:"-"`
	XXX_unrecognized     []byte            `json:"-"`
	XXX_sizecache        int32             `json:"-"`
}

func (m *Context) Reset()         { *m = Context{} }
func (m *Context) String() string { return proto.CompactTextString(m) }
func (*Context) ProtoMessage()    {}
func (*Context) Descriptor() ([]byte, []int) {
	return fileDescriptor_7f73548e33e655fe, []int{0}
}

func (m *Context) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_Context.Unmarshal(m, b)
}
func (m *Context) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_Context.Marshal(b, m, deterministic)
}
func (m *Context) XXX_Merge(src proto.Message) {
	xxx_messageInfo_Context.Merge(m, src)
}
func (m *Context) XXX_Size() int {
	return xxx_messageInfo_Context.Size(m)
}
func (m *Context) XXX_DiscardUnknown() {
	xxx_messageInfo_Context.DiscardUnknown(m)
}

var xxx_messageInfo_Context proto.InternalMessageInfo

func (m *Context) GetCtx() map[string]string {
	if m != nil {
		return m.Ctx
	}
	return nil
}

type Header struct {
	Header               map[string]string `protobuf:"bytes,1,rep,name=header,proto3" json:"header,omitempty" protobuf_key:"bytes,1,opt,name=key,proto3" protobuf_val:"bytes,2,opt,name=value,proto3"`
	XXX_NoUnkeyedLiteral struct{}          `json:"-"`
	XXX_unrecognized     []byte            `json:"-"`
	XXX_sizecache        int32             `json:"-"`
}

func (m *Header) Reset()         { *m = Header{} }
func (m *Header) String() string { return proto.CompactTextString(m) }
func (*Header) ProtoMessage()    {}
func (*Header) Descriptor() ([]byte, []int) {
	return fileDescriptor_7f73548e33e655fe, []int{1}
}

func (m *Header) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_Header.Unmarshal(m, b)
}
func (m *Header) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_Header.Marshal(b, m, deterministic)
}
func (m *Header) XXX_Merge(src proto.Message) {
	xxx_messageInfo_Header.Merge(m, src)
}
func (m *Header) XXX_Size() int {
	return xxx_messageInfo_Header.Size(m)
}
func (m *Header) XXX_DiscardUnknown() {
	xxx_messageInfo_Header.DiscardUnknown(m)
}

var xxx_messageInfo_Header proto.InternalMessageInfo

func (m *Header) GetHeader() map[string]string {
	if m != nil {
		return m.Header
	}
	return nil
}

type Request struct {
	URL                       *any.Any `protobuf:"bytes,1,opt,name=URL,proto3" json:"URL,omitempty"`
	Header                    *Header  `protobuf:"bytes,2,opt,name=header,proto3" json:"header,omitempty"`
	Ctx                       *Context `protobuf:"bytes,3,opt,name=Ctx,proto3" json:"Ctx,omitempty"`
	Depth                     int32    `protobuf:"varint,4,opt,name=Depth,proto3" json:"Depth,omitempty"`
	Method                    string   `protobuf:"bytes,5,opt,name=method,proto3" json:"method,omitempty"`
	Body                      *any.Any `protobuf:"bytes,6,opt,name=Body,proto3" json:"Body,omitempty"`
	ResponseCharacterEncoding string   `protobuf:"bytes,7,opt,name=ResponseCharacterEncoding,proto3" json:"ResponseCharacterEncoding,omitempty"`
	ID                        int32    `protobuf:"varint,8,opt,name=ID,proto3" json:"ID,omitempty"`
	Collector                 *any.Any `protobuf:"bytes,9,opt,name=collector,proto3" json:"collector,omitempty"`
	Abort                     bool     `protobuf:"varint,10,opt,name=abort,proto3" json:"abort,omitempty"`
	BaseURL                   *any.Any `protobuf:"bytes,11,opt,name=baseURL,proto3" json:"baseURL,omitempty"`
	ProxyURL                  string   `protobuf:"bytes,12,opt,name=proxyURL,proto3" json:"proxyURL,omitempty"`
	XXX_NoUnkeyedLiteral      struct{} `json:"-"`
	XXX_unrecognized          []byte   `json:"-"`
	XXX_sizecache             int32    `json:"-"`
}

func (m *Request) Reset()         { *m = Request{} }
func (m *Request) String() string { return proto.CompactTextString(m) }
func (*Request) ProtoMessage()    {}
func (*Request) Descriptor() ([]byte, []int) {
	return fileDescriptor_7f73548e33e655fe, []int{2}
}

func (m *Request) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_Request.Unmarshal(m, b)
}
func (m *Request) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_Request.Marshal(b, m, deterministic)
}
func (m *Request) XXX_Merge(src proto.Message) {
	xxx_messageInfo_Request.Merge(m, src)
}
func (m *Request) XXX_Size() int {
	return xxx_messageInfo_Request.Size(m)
}
func (m *Request) XXX_DiscardUnknown() {
	xxx_messageInfo_Request.DiscardUnknown(m)
}

var xxx_messageInfo_Request proto.InternalMessageInfo

func (m *Request) GetURL() *any.Any {
	if m != nil {
		return m.URL
	}
	return nil
}

func (m *Request) GetHeader() *Header {
	if m != nil {
		return m.Header
	}
	return nil
}

func (m *Request) GetCtx() *Context {
	if m != nil {
		return m.Ctx
	}
	return nil
}

func (m *Request) GetDepth() int32 {
	if m != nil {
		return m.Depth
	}
	return 0
}

func (m *Request) GetMethod() string {
	if m != nil {
		return m.Method
	}
	return ""
}

func (m *Request) GetBody() *any.Any {
	if m != nil {
		return m.Body
	}
	return nil
}

func (m *Request) GetResponseCharacterEncoding() string {
	if m != nil {
		return m.ResponseCharacterEncoding
	}
	return ""
}

func (m *Request) GetID() int32 {
	if m != nil {
		return m.ID
	}
	return 0
}

func (m *Request) GetCollector() *any.Any {
	if m != nil {
		return m.Collector
	}
	return nil
}

func (m *Request) GetAbort() bool {
	if m != nil {
		return m.Abort
	}
	return false
}

func (m *Request) GetBaseURL() *any.Any {
	if m != nil {
		return m.BaseURL
	}
	return nil
}

func (m *Request) GetProxyURL() string {
	if m != nil {
		return m.ProxyURL
	}
	return ""
}

type SerializableRequest struct {
	URL                  string   `protobuf:"bytes,1,opt,name=URL,proto3" json:"URL,omitempty"`
	Method               string   `protobuf:"bytes,2,opt,name=method,proto3" json:"method,omitempty"`
	Body                 [][]byte `protobuf:"bytes,3,rep,name=body,proto3" json:"body,omitempty"`
	ID                   int32    `protobuf:"varint,4,opt,name=ID,proto3" json:"ID,omitempty"`
	Ctx                  *Context `protobuf:"bytes,5,opt,name=ctx,proto3" json:"ctx,omitempty"`
	Headers              *Header  `protobuf:"bytes,6,opt,name=headers,proto3" json:"headers,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *SerializableRequest) Reset()         { *m = SerializableRequest{} }
func (m *SerializableRequest) String() string { return proto.CompactTextString(m) }
func (*SerializableRequest) ProtoMessage()    {}
func (*SerializableRequest) Descriptor() ([]byte, []int) {
	return fileDescriptor_7f73548e33e655fe, []int{3}
}

func (m *SerializableRequest) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_SerializableRequest.Unmarshal(m, b)
}
func (m *SerializableRequest) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_SerializableRequest.Marshal(b, m, deterministic)
}
func (m *SerializableRequest) XXX_Merge(src proto.Message) {
	xxx_messageInfo_SerializableRequest.Merge(m, src)
}
func (m *SerializableRequest) XXX_Size() int {
	return xxx_messageInfo_SerializableRequest.Size(m)
}
func (m *SerializableRequest) XXX_DiscardUnknown() {
	xxx_messageInfo_SerializableRequest.DiscardUnknown(m)
}

var xxx_messageInfo_SerializableRequest proto.InternalMessageInfo

func (m *SerializableRequest) GetURL() string {
	if m != nil {
		return m.URL
	}
	return ""
}

func (m *SerializableRequest) GetMethod() string {
	if m != nil {
		return m.Method
	}
	return ""
}

func (m *SerializableRequest) GetBody() [][]byte {
	if m != nil {
		return m.Body
	}
	return nil
}

func (m *SerializableRequest) GetID() int32 {
	if m != nil {
		return m.ID
	}
	return 0
}

func (m *SerializableRequest) GetCtx() *Context {
	if m != nil {
		return m.Ctx
	}
	return nil
}

func (m *SerializableRequest) GetHeaders() *Header {
	if m != nil {
		return m.Headers
	}
	return nil
}

func init() {
	proto.RegisterType((*Context)(nil), "colly.protofiles.Context")
	proto.RegisterMapType((map[string]string)(nil), "colly.protofiles.Context.CtxEntry")
	proto.RegisterType((*Header)(nil), "colly.protofiles.Header")
	proto.RegisterMapType((map[string]string)(nil), "colly.protofiles.Header.HeaderEntry")
	proto.RegisterType((*Request)(nil), "colly.protofiles.Request")
	proto.RegisterType((*SerializableRequest)(nil), "colly.protofiles.serializableRequest")
}

func init() { proto.RegisterFile("request.proto", fileDescriptor_7f73548e33e655fe) }

var fileDescriptor_7f73548e33e655fe = []byte{
	// 469 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x94, 0x53, 0x41, 0x8b, 0xd3, 0x40,
	0x14, 0x26, 0x99, 0x36, 0x69, 0x5f, 0x57, 0x29, 0xcf, 0x45, 0xa6, 0x3d, 0x85, 0x22, 0x12, 0x58,
	0xc8, 0x4a, 0x15, 0x51, 0xd9, 0x8b, 0xdb, 0x0a, 0x2e, 0x78, 0x1a, 0xf0, 0xe2, 0x6d, 0x92, 0xce,
	0xb6, 0xc5, 0x98, 0xa9, 0x93, 0xa9, 0x26, 0xde, 0xfc, 0x6f, 0x1e, 0xfd, 0x51, 0x32, 0x33, 0x49,
	0xab, 0x2e, 0x0d, 0xec, 0xa9, 0xef, 0x7b, 0xfd, 0x66, 0xde, 0xf7, 0xbe, 0x6f, 0x02, 0x0f, 0x94,
	0xf8, 0xba, 0x17, 0xa5, 0x4e, 0x76, 0x4a, 0x6a, 0x89, 0xe3, 0x4c, 0xe6, 0x79, 0xed, 0xc0, 0xed,
	0x36, 0x17, 0xe5, 0x74, 0xb2, 0x96, 0x72, 0x9d, 0x8b, 0x4b, 0xdb, 0x4a, 0xf7, 0xb7, 0x97, 0xbc,
	0x68, 0xfe, 0x9f, 0x7d, 0x87, 0x70, 0x21, 0x0b, 0x2d, 0x2a, 0x8d, 0x2f, 0x80, 0x2c, 0x74, 0x45,
	0xbd, 0x88, 0xc4, 0xa3, 0xf9, 0x2c, 0xf9, 0xff, 0x96, 0xa4, 0xe1, 0x25, 0x0b, 0x5d, 0xbd, 0x2b,
	0xb4, 0xaa, 0x99, 0xa1, 0x4f, 0x5f, 0xc2, 0xa0, 0x6d, 0xe0, 0x18, 0xc8, 0x67, 0x51, 0x53, 0x2f,
	0xf2, 0xe2, 0x21, 0x33, 0x25, 0x9e, 0x43, 0xff, 0x1b, 0xcf, 0xf7, 0x82, 0xfa, 0xb6, 0xe7, 0xc0,
	0x1b, 0xff, 0x95, 0x37, 0xfb, 0xe9, 0x41, 0xf0, 0x5e, 0xf0, 0x95, 0x50, 0x78, 0x05, 0xc1, 0xc6,
	0x56, 0xcd, 0xec, 0x27, 0x77, 0x67, 0x3b, 0x66, 0xf3, 0xe3, 0xa6, 0x37, 0x67, 0xa6, 0xaf, 0x61,
	0xf4, 0x57, 0xfb, 0x5e, 0x1a, 0x7e, 0x13, 0x08, 0x99, 0xf3, 0x0e, 0x9f, 0x02, 0xf9, 0xc8, 0x3e,
	0xd8, 0x73, 0xa3, 0xf9, 0x79, 0xe2, 0x1c, 0x4b, 0x5a, 0xc7, 0x92, 0xb7, 0x45, 0xcd, 0x0c, 0x01,
	0x9f, 0x1d, 0xc4, 0xfa, 0x96, 0x4a, 0x4f, 0x89, 0x6d, 0x05, 0xe2, 0x85, 0xf3, 0x95, 0x58, 0xfa,
	0xe4, 0xa4, 0xaf, 0xd6, 0x4e, 0x23, 0x76, 0x29, 0x76, 0x7a, 0x43, 0x7b, 0x91, 0x17, 0xf7, 0x99,
	0x03, 0xf8, 0x18, 0x82, 0x2f, 0x42, 0x6f, 0xe4, 0x8a, 0xf6, 0xed, 0x0e, 0x0d, 0xc2, 0x18, 0x7a,
	0xd7, 0x72, 0x55, 0xd3, 0xa0, 0x43, 0xb5, 0x65, 0xe0, 0x15, 0x4c, 0x98, 0x28, 0x77, 0xb2, 0x28,
	0xc5, 0x62, 0xc3, 0x15, 0xcf, 0xb4, 0x31, 0x2c, 0x93, 0xab, 0x6d, 0xb1, 0xa6, 0xa1, 0xbd, 0xf4,
	0x34, 0x01, 0x1f, 0x82, 0x7f, 0xb3, 0xa4, 0x03, 0x2b, 0xc9, 0xbf, 0x59, 0xe2, 0x1c, 0x86, 0x66,
	0x0d, 0x91, 0x69, 0xa9, 0xe8, 0xb0, 0x63, 0xf8, 0x91, 0x66, 0x36, 0xe3, 0xa9, 0x54, 0x9a, 0x42,
	0xe4, 0xc5, 0x03, 0xe6, 0x00, 0x26, 0x10, 0xa6, 0xbc, 0x14, 0xc6, 0xfa, 0x51, 0xc7, 0x3d, 0x2d,
	0x09, 0xa7, 0x30, 0xd8, 0x29, 0x59, 0xd5, 0xe6, 0xc0, 0x99, 0x95, 0x7d, 0xc0, 0xb3, 0x5f, 0x1e,
	0x3c, 0x2a, 0x85, 0xda, 0xf2, 0x7c, 0xfb, 0x83, 0xa7, 0xb9, 0x68, 0xa3, 0x1d, 0x1f, 0xa3, 0x1d,
	0xba, 0x10, 0x8f, 0x7e, 0xfa, 0xff, 0xf8, 0x89, 0xd0, 0x4b, 0x8d, 0x9f, 0x24, 0x22, 0xf1, 0x19,
	0xb3, 0x75, 0xb3, 0x7b, 0xef, 0xb0, 0xfb, 0x05, 0x90, 0x4c, 0x57, 0x36, 0x88, 0xee, 0x38, 0x33,
	0x5d, 0xe1, 0x1c, 0x42, 0xf7, 0x0a, 0xca, 0x26, 0xa3, 0xd3, 0xcf, 0xa5, 0x25, 0x5e, 0xe3, 0xa7,
	0x3b, 0x5f, 0x70, 0x1a, 0xd8, 0xfa, 0xf9, 0x9f, 0x00, 0x00, 0x00, 0xff, 0xff, 0x5f, 0xf2, 0x6a,
	0x3f, 0xeb, 0x03, 0x00, 0x00,
}