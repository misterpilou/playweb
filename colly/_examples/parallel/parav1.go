package main

import (
	"fmt"
        "os"
        "os/signal"
        "syscall"

	"github.com/gocolly/colly"
)

func main() {
        sig := make(chan os.Signal)
        signal.Notify(sig, os.Interrupt, syscall.SIGTERM)
        
	// Instantiate default collector
	c := colly.NewCollector(
		// MaxDepth is 2, so only the links on the scraped page
		// and links on those pages are visited
		colly.MaxDepth(2),
		colly.Async(true),
	)

	// Limit the maximum parallelism to 2
	// This is necessary if the goroutines are dynamically
	// created to control the limit of simultaneous requests.
	//
	// Parallelism can be controlled also by spawning fixed
	// number of go routines.
	c.Limit(&colly.LimitRule{DomainGlob: "*", Parallelism: 8})

        i := 0
        j := 0

        c.OnResponse(func(res *colly.Response) {
            //fmt.Println(string(res.Body))
            if (res.StatusCode == 200) {
                i++
            }
            j++
        })

        c.OnRequest(func(req *colly.Request) {
            fmt.Println(req.URL)
        })

	// On every a element which has href attribute call callback
	c.OnHTML("a[href]", func(e *colly.HTMLElement) {
		link := e.Attr("href")
		// Print link
		// fmt.Println(link)
		// Visit link found on page on a new thread
		// e.Request.Visit(link)
                c.Visit(link)
	})

	// Start scraping on https://en.wikipedia.org
	c.Visit("https://en.wikipedia.org/")
	// Wait until threads are finished
        go func() {
            <-sig
            fmt.Println("number of 200 ", i)
            fmt.Println("number of request ", j)
            os.Exit(1)
        }()
	c.Wait()
}
