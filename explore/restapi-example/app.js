const express = require('express')
const default_router = require('./default_router')
const app = express()
const port = 3000

app.use('/', default_router)

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})
