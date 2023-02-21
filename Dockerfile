# Build stage
FROM golang:alpine AS builder
WORKDIR /app
COPY . .
RUN go build -o main main.go
RUN apk --no-cache add curl

# Run stage
FROM alpine
WORKDIR /app
COPY --from=builder /app/main .
COPY app.env .
COPY start.sh .
COPY wait-for.sh .
COPY db/migration ./db/migration

EXPOSE 8080
CMD [ "/app/main" ]
ENTRYPOINT [ "/app/start.sh" ]